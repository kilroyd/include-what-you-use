//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/stdalign_h/alignof-d1.h"

// IWYU: alignof is defined in...*stdalign.h
void foo(void) { (void) alignof(char); }

/**** IWYU_SUMMARY

tests/stdlib/c/stdalign_h/alignof.c should add these lines:
#include <stdalign.h>

tests/stdlib/c/stdalign_h/alignof.c should remove these lines:
- #include "tests/stdlib/c/stdalign_h/alignof-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/stdalign_h/alignof.c:
#include <stdalign.h>  // for alignof

***** IWYU_SUMMARY */
