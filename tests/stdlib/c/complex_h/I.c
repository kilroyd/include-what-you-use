//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/complex_h/I-d1.h"

// IWYU: I is defined in...*complex.h
void foo(void) { (void) I; }

/**** IWYU_SUMMARY

tests/stdlib/c/complex_h/I.c should add these lines:
#include <complex.h>

tests/stdlib/c/complex_h/I.c should remove these lines:
- #include "tests/stdlib/c/complex_h/I-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/complex_h/I.c:
#include <complex.h>  // for I

***** IWYU_SUMMARY */
