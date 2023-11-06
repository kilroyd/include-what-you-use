//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/limits_h/LLONG_MIN-d1.h"

// IWYU: LLONG_MIN is defined in...*limits.h
void foo(void) { (void) LLONG_MIN; }

/**** IWYU_SUMMARY

tests/stdlib/c/limits_h/LLONG_MIN.c should add these lines:
#include <limits.h>

tests/stdlib/c/limits_h/LLONG_MIN.c should remove these lines:
- #include "tests/stdlib/c/limits_h/LLONG_MIN-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/limits_h/LLONG_MIN.c:
#include <limits.h>  // for LLONG_MIN

***** IWYU_SUMMARY */
