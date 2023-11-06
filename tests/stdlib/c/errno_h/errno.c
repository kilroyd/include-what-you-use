//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/errno_h/errno-d1.h"

// IWYU: errno is defined in...*errno.h
void foo(void) { (void) errno; }

/**** IWYU_SUMMARY

tests/stdlib/c/errno_h/errno.c should add these lines:
#include <errno.h>

tests/stdlib/c/errno_h/errno.c should remove these lines:
- #include "tests/stdlib/c/errno_h/errno-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/errno_h/errno.c:
#include <errno.h>  // for errno

***** IWYU_SUMMARY */
