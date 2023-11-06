//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/locale_h/LC_CTYPE-d1.h"

// IWYU: LC_CTYPE is defined in...*locale.h
void foo(void) { (void) LC_CTYPE; }

/**** IWYU_SUMMARY

tests/stdlib/c/locale_h/LC_CTYPE.c should add these lines:
#include <locale.h>

tests/stdlib/c/locale_h/LC_CTYPE.c should remove these lines:
- #include "tests/stdlib/c/locale_h/LC_CTYPE-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/locale_h/LC_CTYPE.c:
#include <locale.h>  // for LC_CTYPE

***** IWYU_SUMMARY */
