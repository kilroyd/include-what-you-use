//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/float_h/LDBL_DECIMAL_DIG-d1.h"

// IWYU: LDBL_DECIMAL_DIG is defined in...*float.h
void foo(void) { (void) LDBL_DECIMAL_DIG; }

/**** IWYU_SUMMARY

tests/stdlib/c/float_h/LDBL_DECIMAL_DIG.c should add these lines:
#include <float.h>

tests/stdlib/c/float_h/LDBL_DECIMAL_DIG.c should remove these lines:
- #include "tests/stdlib/c/float_h/LDBL_DECIMAL_DIG-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/float_h/LDBL_DECIMAL_DIG.c:
#include <float.h>  // for LDBL_DECIMAL_DIG

***** IWYU_SUMMARY */
