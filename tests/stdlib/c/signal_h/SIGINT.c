//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/signal_h/SIGINT-d1.h"

// IWYU: SIGINT is defined in...*signal.h
void foo(void) { (void) SIGINT; }

/**** IWYU_SUMMARY

tests/stdlib/c/signal_h/SIGINT.c should add these lines:
#include <signal.h>

tests/stdlib/c/signal_h/SIGINT.c should remove these lines:
- #include "tests/stdlib/c/signal_h/SIGINT-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/signal_h/SIGINT.c:
#include <signal.h>  // for SIGINT

***** IWYU_SUMMARY */
