//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/stdalign_h/alignas-d1.h"

// IWYU: alignas is defined in...*stdalign.h
alignas(64) char c[8];

/**** IWYU_SUMMARY

tests/stdlib/c/stdalign_h/alignas.c should add these lines:
#include <stdalign.h>

tests/stdlib/c/stdalign_h/alignas.c should remove these lines:
- #include "tests/stdlib/c/stdalign_h/alignas-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/stdalign_h/alignas.c:
#include <stdalign.h>  // for alignas

***** IWYU_SUMMARY */
