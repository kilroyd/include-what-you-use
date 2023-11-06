# ===- cppreference_parser.py -  ------------------------------*- python -*--===#
#
# Adapted from cppreference_parser.py from the LLVM Project, under the
# Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
# ===------------------------------------------------------------------------===#

from bs4 import BeautifulSoup, NavigableString

import collections
import multiprocessing
import os
import re
import signal
import sys


class Symbol:
    def __init__(self, name, namespace, headers):
        # unqualifed symbol name, e.g. "move"
        self.name = name
        # namespace of the symbol (with trailing "::"), e.g. "std::", "" (global scope)
        # None for C symbols.
        self.namespace = namespace
        # a list of corresponding headers
        self.headers = headers

    def __lt__(self, other):
        return str(self) < str(other)

    def __str__(self):
        if self.namespace:
            return self.namespace + self.name
        return self.name


class SimpleMacro(Symbol):
    """A basic macro i.e. not function-like.

    Technically a macro could try to do anything. Assume that the
    macro being defined in the standard maps to a value.

    #define A 1
    """

    def __init__(self, name, namespace, headers, keyword):
        assert(namespace is None)
        Symbol.__init__(self, name, namespace, headers)

        # True if this is a macro that expands to a keyword
        self.keyword = keyword

    # TODO: move to gen_stdlib_tests.py
    def getTestText(self):
        if not(self.keyword):
            return 'void foo(void) { (void) ' + self.name + '; }'

        # Handle keyword macros
        keyword_test = {
            'alignas': 'alignas(64) char c[8];',
            'alignof': 'void foo(void) { (void) alignof(char); }',
            'bool': 'bool v1;',
            'complex': 'complex cmplx;',
            'imaginary': 'imaginary imag;',
            'noreturn': 'noreturn void foo(){ while(1); }',
            'static_assert': 'static_assert(1, "never fail");',
            'thread_local': 'thread_local char tlc;',
        }
        assert(self.name in keyword_test)

        return keyword_test[self.name]


def _HasClass(tag, *classes):
    for c in tag.get("class", []):
        if c in classes:
            return True
    return False


def _ParseSymbolPage(symbol_page_html, namespace, symbol_name, macro_hint):
    """Parse symbol page and retrieve the include header defined in this page.
    The symbol page provides header for the symbol, specifically in
    "Defined in header <header>" section. An example:

    <tr class="t-dsc-header">
      <td colspan="2"> <div>Defined in header <code>&lt;ratio&gt;</code> </div>
    </td></tr>

    Returns a list of Symbols.
    """
    symbols = []
    symbol_re = re.compile(r'\b' + symbol_name + r'\b')
    prev_headers = None
    soup = BeautifulSoup(symbol_page_html, "html.parser")
    # Rows in table are like:
    #   Defined in header <foo>      .t-dsc-header
    #   Defined in header <bar>      .t-dsc-header
    #   decl1                        .t-dcl
    #   Defined in header <baz>      .t-dsc-header
    #   decl2                        .t-dcl
    for table in soup.select("table.t-dcl-begin, table.t-dsc-begin"):
        current_headers = []
        declarations = []
        was_decl = False
        added = False
        for row in table.select("tr"):
            if _HasClass(row, "t-dcl", "t-dsc"):
                was_decl = True
                # Symbols are in the first cell.
                td = row.find("td")
                found_symbols = td.stripped_strings
                functionlike = False
                defined = False
                found = False
                for sym in found_symbols:
                    if '#define' in sym:
                        defined = True
                    if symbol_re.search(sym):
                        found = True
                        if '(' in sym:
                            functionlike = True
                        break
                if not found:
                    continue
                if len(current_headers) == 0 and prev_headers is not None:
                    # Re-use headers from previous table
                    current_headers = prev_headers
                if (_HasClass(row, "t-dsc") or defined) and not(functionlike):
                    keyword = 'keyword macro' in macro_hint if macro_hint else False
                    symbols.append(SimpleMacro(symbol_name, namespace, current_headers, keyword))
                    added = True
                # TODO: identify and handle structs, enums, unions,
                # functions and function like macros
            elif _HasClass(row, "t-dsc-header"):
                # If we saw a decl since the last header, this is a new block of headers
                # for a new block of decls.
                if was_decl:
                    current_headers = []

                was_decl = False
                # There are also .t-dsc-header for "defined in namespace".
                if not "Defined in header " in row.text:
                    continue
                # The interesting header content (e.g. <cstdlib>) is wrapped in <code>.
                for header_code in row.find_all("code"):
                    current_headers.append(header_code.text)

        if added:
            # We've found symbols in a table, no need to match in later tables
            # TODO: Is this still true for cpp?
            #
            # Breaking here avoids adding 2 EXIT_FAILURES in C, one
            # from t-dcl and another from t-dsc
            break
        prev_headers = current_headers

    return symbols


def _ParseIndexPage(index_page_html):
    """Parse index page.
    The index page lists all std symbols and hrefs to their detailed pages
    (which contain the defined header). An example:

    <a href="abs.html" title="abs"><tt>abs()</tt></a> (int) <br>
    <a href="acos.html" title="acos"><tt>acos()</tt></a>  (optional variant)
         <span class="t-mark">(optional hint)</span>
         <span class="t-mark-rev"> (optional since) </span> <br>

    Returns a list of tuple (symbol_name, relative_path_to_symbol_page, variant, macro_hint).
    """
    symbols = []
    soup = BeautifulSoup(index_page_html, "html.parser")
    for symbol_href in soup.select("a[title]"):
        # Capture separate variants like "acos<>() (std::complex)" so
        # we produce tests for each variant.
        #
        # Note: std::swap doesn't list its specializations in the index.
        #
        # Also capture macro information from the index page, as the
        # symbol pages aren't consistent in how they list this
        # information. In particular we want to capture "(keyword
        # macro)"
        tag = symbol_href.next_sibling
        variant = None
        macro_hint = None
        if isinstance(tag, NavigableString) and "(" in tag:
            variant = tag.text.strip(' ()')
        elif tag:
            if tag.name == 'span' and _HasClass(tag, 't-mark'):
                macro_hint = tag.text.strip(' ()')
            else:
                tag = tag.next_sibling
                if tag and tag.name == 'span' and _HasClass(tag, 't-mark'):
                    macro_hint = tag.text.strip(' ()')
        symbol_tt = symbol_href.find("tt")
        if symbol_tt:
            symbols.append(
                (
                    symbol_tt.text.rstrip("<>()"),  # strip any trailing <>()
                    symbol_href["href"],
                    variant,
                    macro_hint
                )
            )
    return symbols


def _ReadSymbolPage(path, namespace, name, macro_hint):
    with open(path) as f:
        return _ParseSymbolPage(f.read(), namespace, name, macro_hint)


def _GetSymbols(pool, root_dir, index_page_name, namespace):
    """Get all symbols listed in the index page. All symbols should be in the
    given namespace.

    Returns a list of Symbols.
    """

    # Workflow steps:
    #   1. Parse index page which lists all symbols to get symbol
    #      name (unqualified name) and its href link to the symbol page which
    #      contains the defined header.
    #   2. Parse the symbol page to get symbol information
    index_page_path = os.path.join(root_dir, index_page_name)
    results = []  # (symbol_name, promise of [header...])
    with open(index_page_path, "r") as f:
        # Read each symbol page in parallel.
        for symbol_name, symbol_page_path, variant, macro_hint in _ParseIndexPage(f.read()):
            path = os.path.join(root_dir, symbol_page_path)
            if os.path.isfile(path):
                results.append(
                    (
                        symbol_name,
                        pool.apply_async(_ReadSymbolPage, (path, namespace, symbol_name, macro_hint)),
                    )
                )
            else:
                sys.stderr.write(
                    "Discarding information for symbol: %s(%s). Page %s does not exist.\n"
                    % (symbol_name, variant, path)
                )

    # Build map from symbol name to a set of headers.
    symbols = []
    for symbol_name, lazy_syminfo in results:
        symbols.extend(lazy_syminfo.get())

    return sorted(symbols)


def GetSymbols(parse_pages):
    """Get all symbols by parsing the given pages.

    Args:
      parse_pages: a list of tuples (page_root_dir, index_page_name, namespace)
    """
    symbols = []
    # Run many workers to process individual symbol pages under the symbol index.
    # Don't allow workers to capture Ctrl-C.
    pool = multiprocessing.Pool(
        # TODO: this doesn't compile for me
        # initializer=lambda: signal.signal(signal.SIGINT, signal.SIG_IGN)
    )
    try:
        for root_dir, page_name, namespace in parse_pages:
            symbols.extend(
                _GetSymbols(pool, root_dir, page_name, namespace)
            )
    finally:
        pool.terminate()
        pool.join()
    return symbols
