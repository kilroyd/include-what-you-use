//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/time_h/CLOCKS_PER_SEC-d1.h"

// IWYU: CLOCKS_PER_SEC is defined in...*time.h
void foo(void) { (void) CLOCKS_PER_SEC; }

/**** IWYU_SUMMARY

tests/stdlib/c/time_h/CLOCKS_PER_SEC.c should add these lines:
#include <time.h>

tests/stdlib/c/time_h/CLOCKS_PER_SEC.c should remove these lines:
- #include "tests/stdlib/c/time_h/CLOCKS_PER_SEC-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/time_h/CLOCKS_PER_SEC.c:
#include <time.h>  // for CLOCKS_PER_SEC

***** IWYU_SUMMARY */
