//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/fenv_h/FE_INEXACT-d1.h"

// IWYU: FE_INEXACT is defined in...*fenv.h
void foo(void) { (void) FE_INEXACT; }

/**** IWYU_SUMMARY

tests/stdlib/c/fenv_h/FE_INEXACT.c should add these lines:
#include <fenv.h>

tests/stdlib/c/fenv_h/FE_INEXACT.c should remove these lines:
- #include "tests/stdlib/c/fenv_h/FE_INEXACT-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/fenv_h/FE_INEXACT.c:
#include <fenv.h>  // for FE_INEXACT

***** IWYU_SUMMARY */
