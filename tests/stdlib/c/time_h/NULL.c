//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/time_h/NULL-d1.h"

// IWYU: NULL is defined in...*time.h
void foo(void) { (void) NULL; }

/**** IWYU_SUMMARY

tests/stdlib/c/time_h/NULL.c should add these lines:
#include <time.h>

tests/stdlib/c/time_h/NULL.c should remove these lines:
- #include "tests/stdlib/c/time_h/NULL-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/time_h/NULL.c:
#include <time.h>  // for NULL

***** IWYU_SUMMARY */
