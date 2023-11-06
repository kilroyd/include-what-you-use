//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/stdint_h/UINTPTR_MAX-d1.h"

// IWYU: UINTPTR_MAX is defined in...*stdint.h
void foo(void) { (void) UINTPTR_MAX; }

/**** IWYU_SUMMARY

tests/stdlib/c/stdint_h/UINTPTR_MAX.c should add these lines:
#include <stdint.h>

tests/stdlib/c/stdint_h/UINTPTR_MAX.c should remove these lines:
- #include "tests/stdlib/c/stdint_h/UINTPTR_MAX-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/stdint_h/UINTPTR_MAX.c:
#include <stdint.h>  // for UINTPTR_MAX

***** IWYU_SUMMARY */
