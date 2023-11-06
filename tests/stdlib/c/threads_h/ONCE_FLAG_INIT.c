//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/threads_h/ONCE_FLAG_INIT-d1.h"

// IWYU: ONCE_FLAG_INIT is defined in...*threads.h
void foo(void) { (void) ONCE_FLAG_INIT; }

/**** IWYU_SUMMARY

tests/stdlib/c/threads_h/ONCE_FLAG_INIT.c should add these lines:
#include <threads.h>

tests/stdlib/c/threads_h/ONCE_FLAG_INIT.c should remove these lines:
- #include "tests/stdlib/c/threads_h/ONCE_FLAG_INIT-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/threads_h/ONCE_FLAG_INIT.c:
#include <threads.h>  // for ONCE_FLAG_INIT

***** IWYU_SUMMARY */
