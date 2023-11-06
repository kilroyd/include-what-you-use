//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/float_h/FLT_HAS_SUBNORM-d1.h"

// IWYU: FLT_HAS_SUBNORM is defined in...*float.h
void foo(void) { (void) FLT_HAS_SUBNORM; }

/**** IWYU_SUMMARY

tests/stdlib/c/float_h/FLT_HAS_SUBNORM.c should add these lines:
#include <float.h>

tests/stdlib/c/float_h/FLT_HAS_SUBNORM.c should remove these lines:
- #include "tests/stdlib/c/float_h/FLT_HAS_SUBNORM-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/float_h/FLT_HAS_SUBNORM.c:
#include <float.h>  // for FLT_HAS_SUBNORM

***** IWYU_SUMMARY */
