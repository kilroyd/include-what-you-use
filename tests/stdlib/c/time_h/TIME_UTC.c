//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/time_h/TIME_UTC-d1.h"

// IWYU: TIME_UTC is defined in...*time.h
void foo(void) { (void) TIME_UTC; }

/**** IWYU_SUMMARY

tests/stdlib/c/time_h/TIME_UTC.c should add these lines:
#include <time.h>

tests/stdlib/c/time_h/TIME_UTC.c should remove these lines:
- #include "tests/stdlib/c/time_h/TIME_UTC-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/time_h/TIME_UTC.c:
#include <time.h>  // for TIME_UTC

***** IWYU_SUMMARY */
