//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/wchar_h/NULL-d1.h"

// IWYU: NULL is defined in...*wchar.h
void foo(void) { (void) NULL; }

/**** IWYU_SUMMARY

tests/stdlib/c/wchar_h/NULL.c should add these lines:
#include <wchar.h>

tests/stdlib/c/wchar_h/NULL.c should remove these lines:
- #include "tests/stdlib/c/wchar_h/NULL-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/wchar_h/NULL.c:
#include <wchar.h>  // for NULL

***** IWYU_SUMMARY */
