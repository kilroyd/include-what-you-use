//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/wchar_h/WCHAR_MIN-d1.h"

// IWYU: WCHAR_MIN is defined in...*wchar.h
void foo(void) { (void) WCHAR_MIN; }

/**** IWYU_SUMMARY

tests/stdlib/c/wchar_h/WCHAR_MIN.c should add these lines:
#include <wchar.h>

tests/stdlib/c/wchar_h/WCHAR_MIN.c should remove these lines:
- #include "tests/stdlib/c/wchar_h/WCHAR_MIN-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/wchar_h/WCHAR_MIN.c:
#include <wchar.h>  // for WCHAR_MIN

***** IWYU_SUMMARY */
