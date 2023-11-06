//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/limits_h/ULLONG_WIDTH-d1.h"

// IWYU: ULLONG_WIDTH is defined in...*limits.h
void foo(void) { (void) ULLONG_WIDTH; }

/**** IWYU_SUMMARY

tests/stdlib/c/limits_h/ULLONG_WIDTH.c should add these lines:
#include <limits.h>

tests/stdlib/c/limits_h/ULLONG_WIDTH.c should remove these lines:
- #include "tests/stdlib/c/limits_h/ULLONG_WIDTH-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/limits_h/ULLONG_WIDTH.c:
#include <limits.h>  // for ULLONG_WIDTH

***** IWYU_SUMMARY */
