//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/assert_h/static_assert-d1.h"

// IWYU: static_assert is defined in...*assert.h
static_assert(1, "never fail");

/**** IWYU_SUMMARY

tests/stdlib/c/assert_h/static_assert.c should add these lines:
#include <assert.h>

tests/stdlib/c/assert_h/static_assert.c should remove these lines:
- #include "tests/stdlib/c/assert_h/static_assert-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/assert_h/static_assert.c:
#include <assert.h>  // for static_assert

***** IWYU_SUMMARY */
