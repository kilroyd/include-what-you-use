#!/usr/bin/env python3
# ===- gen_stdlib_tests.py -  ---------------------------------*- python -*--===#
#
# Adapted from gen_std.py from the LLVM Project, under the Apache
# License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
# ===------------------------------------------------------------------------===#

"""gen_stdlib_tests.py is a tool to generate tests for C/C++ Standard
Library symbols by parsing archived HTML files from cppreference.

The generated files are located in tests/stdlib.

Usage:
  1. Install BeautifulSoup dependency, see instruction:
       https://www.crummy.com/software/BeautifulSoup/bs4/doc/#installing-beautiful-soup
  2. Download cppreference offline HTML files (html_book_20230810.zip in Unofficial Release) at
       https://en.cppreference.com/w/Cppreference:Archives
  3. Unzip the zip file from step 2 (e.g., to a "cppreference" directory). You should
     get a "cppreference/reference" directory.
  4. Run the command:
       // Generate C++ tests
       python3 gen_stdlib_tests.py --cppreference cppreference/reference --symbols=cpp
       // Generate C tests
       python3 gen_stdlib_tests.py --cppreference cppreference/reference --symbols=c
"""


import cppreference_parser
import argparse
import datetime
import os
import sys
import re


CODE_PREFIX = """\
//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on %s).
//===----------------------------------------------------------------------===//
"""


TEST_H_TEMPLATE = """\
#include %s
"""


TEST_TU_TEMPLATE = """\
// IWYU_ARGS: -I.

#include "tests/stdlib/{basepath}-d1.h"

// IWYU: {symbol} is defined in...*{header}
{test}

/**** IWYU_SUMMARY

tests/stdlib/{basepath}{suffix} should add these lines:
#include <{header}>

tests/stdlib/{basepath}{suffix} should remove these lines:
- #include "tests/stdlib/{basepath}-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/{basepath}{suffix}:
#include <{header}>  // for {symbol}

***** IWYU_SUMMARY */
"""


def ParseArg():
    parser = argparse.ArgumentParser(description='Generate stdlib test files')
    parser.add_argument(
        '--cppreference',
        metavar='PATH',
        default='',
        help='path to the cppreference offline HTML directory',
        required=True,
    )
    parser.add_argument(
        '--symbols',
        default='cpp',
        help='Generate c or cpp (removed) symbols. One of {cpp, c, cpp_removed}.',
    )
    parser.add_argument(
        '--outputdir',
        '-o',
        default='.',
        help="Output directory",
    )
    return parser.parse_args()


def main():
    args = ParseArg()
    if args.symbols == "cpp":
        page_root = os.path.join(args.cppreference, "en", "cpp")
        symbol_index_root = os.path.join(page_root, "symbol_index")
        parse_pages = [
            (symbol_index_root, "macro.html", None),
        ]
    elif args.symbols == "c":
        page_root = os.path.join(args.cppreference, "en", "c")
        symbol_index_root = os.path.join(page_root, "symbol_index")
        parse_pages = [
            (symbol_index_root, "macro.html", None)
        ]

    if not os.path.exists(symbol_index_root):
        exit("Path %s doesn't exist!" % symbol_index_root)

    symbols = cppreference_parser.GetSymbols(parse_pages)

    headers = set();
    # Get a list of all headers
    for symbol in symbols:
        headers.update(symbol.headers)

    # We don't have version information from the unzipped offline HTML files.
    # so we use the modified time of the symbol_index.html as the version.
    index_page_path = os.path.join(page_root, "index.html")
    cppreference_modified_date = datetime.datetime.fromtimestamp(
        os.stat(index_page_path).st_mtime
    ).strftime("%Y-%m-%d")

    suffix = '.cc' if args.symbols == 'cpp' else '.c'

    try:
        os.mkdir(os.path.join(args.outputdir, args.symbols))
    except FileExistsError:
        pass

    # Generate a file per symbol, so we can annotate stdlib version
    # validity.
    for symbol in symbols:
        for header in symbol.headers:
            bare_header = header.strip('<>')
            sanitized_header = bare_header.replace('.', '_')
            basedir = os.path.join(args.symbols, sanitized_header)
            try:
                os.mkdir(os.path.join(args.outputdir, basedir))
            except FileExistsError:
                pass
            basepath = os.path.join(basedir, str(symbol))
            with open(os.path.join(args.outputdir, basepath + '-d1.h'), 'w') as f:
                f.write(CODE_PREFIX % (cppreference_modified_date))
                f.write(TEST_H_TEMPLATE % (header))

            with open(os.path.join(args.outputdir, basepath + suffix), 'w') as f:
                test = symbol.getTestText()
                f.write(CODE_PREFIX % (cppreference_modified_date))
                f.write(TEST_TU_TEMPLATE.format(basepath=basepath,
                                                suffix=suffix,
                                                header=bare_header,
                                                symbol=symbol,
                                                test=test))

                # TODO: Generate output for something like
                # IWYU_REQUIRED: since_libc_version(c99)
                # IWYU_REQUIRED: since_libcxx_version(c++17)
                # IWYU_REQUIRED: until_libcxx_version(c++20)

if __name__ == "__main__":
    main()
