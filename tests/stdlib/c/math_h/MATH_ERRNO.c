//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/math_h/MATH_ERRNO-d1.h"

// IWYU: MATH_ERRNO is defined in...*math.h
void foo(void) { (void) MATH_ERRNO; }

/**** IWYU_SUMMARY

tests/stdlib/c/math_h/MATH_ERRNO.c should add these lines:
#include <math.h>

tests/stdlib/c/math_h/MATH_ERRNO.c should remove these lines:
- #include "tests/stdlib/c/math_h/MATH_ERRNO-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/math_h/MATH_ERRNO.c:
#include <math.h>  // for MATH_ERRNO

***** IWYU_SUMMARY */
