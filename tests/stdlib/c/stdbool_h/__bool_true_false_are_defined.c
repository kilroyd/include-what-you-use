//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/stdbool_h/__bool_true_false_are_defined-d1.h"

// IWYU: __bool_true_false_are_defined is defined in...*stdbool.h
void foo(void) { (void) __bool_true_false_are_defined; }

/**** IWYU_SUMMARY

tests/stdlib/c/stdbool_h/__bool_true_false_are_defined.c should add these lines:
#include <stdbool.h>

tests/stdlib/c/stdbool_h/__bool_true_false_are_defined.c should remove these lines:
- #include "tests/stdlib/c/stdbool_h/__bool_true_false_are_defined-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/stdbool_h/__bool_true_false_are_defined.c:
#include <stdbool.h>  // for __bool_true_false_are_defined

***** IWYU_SUMMARY */
