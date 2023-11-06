//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/locale_h/LC_TIME-d1.h"

// IWYU: LC_TIME is defined in...*locale.h
void foo(void) { (void) LC_TIME; }

/**** IWYU_SUMMARY

tests/stdlib/c/locale_h/LC_TIME.c should add these lines:
#include <locale.h>

tests/stdlib/c/locale_h/LC_TIME.c should remove these lines:
- #include "tests/stdlib/c/locale_h/LC_TIME-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/locale_h/LC_TIME.c:
#include <locale.h>  // for LC_TIME

***** IWYU_SUMMARY */
