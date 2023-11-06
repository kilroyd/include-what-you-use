//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/stdnoreturn_h/noreturn-d1.h"

// IWYU: noreturn is defined in...*stdnoreturn.h
noreturn void foo(){}

/**** IWYU_SUMMARY

tests/stdlib/c/stdnoreturn_h/noreturn.c should add these lines:
#include <stdnoreturn.h>

tests/stdlib/c/stdnoreturn_h/noreturn.c should remove these lines:
- #include "tests/stdlib/c/stdnoreturn_h/noreturn-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/stdnoreturn_h/noreturn.c:
#include <stdnoreturn.h>  // for noreturn

***** IWYU_SUMMARY */
