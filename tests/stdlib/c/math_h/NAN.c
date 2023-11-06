//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/math_h/NAN-d1.h"

// IWYU: NAN is defined in...*math.h
void foo(void) { (void) NAN; }

/**** IWYU_SUMMARY

tests/stdlib/c/math_h/NAN.c should add these lines:
#include <math.h>

tests/stdlib/c/math_h/NAN.c should remove these lines:
- #include "tests/stdlib/c/math_h/NAN-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/math_h/NAN.c:
#include <math.h>  // for NAN

***** IWYU_SUMMARY */
