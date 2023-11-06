//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/threads_h/TSS_DTOR_ITERATIONS-d1.h"

// IWYU: TSS_DTOR_ITERATIONS is defined in...*threads.h
void foo(void) { (void) TSS_DTOR_ITERATIONS; }

/**** IWYU_SUMMARY

tests/stdlib/c/threads_h/TSS_DTOR_ITERATIONS.c should add these lines:
#include <threads.h>

tests/stdlib/c/threads_h/TSS_DTOR_ITERATIONS.c should remove these lines:
- #include "tests/stdlib/c/threads_h/TSS_DTOR_ITERATIONS-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/threads_h/TSS_DTOR_ITERATIONS.c:
#include <threads.h>  // for TSS_DTOR_ITERATIONS

***** IWYU_SUMMARY */
