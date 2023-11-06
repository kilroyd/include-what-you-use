//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/wctype_h/WEOF-d1.h"

// IWYU: WEOF is defined in...*wctype.h
void foo(void) { (void) WEOF; }

/**** IWYU_SUMMARY

tests/stdlib/c/wctype_h/WEOF.c should add these lines:
#include <wctype.h>

tests/stdlib/c/wctype_h/WEOF.c should remove these lines:
- #include "tests/stdlib/c/wctype_h/WEOF-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/wctype_h/WEOF.c:
#include <wctype.h>  // for WEOF

***** IWYU_SUMMARY */
