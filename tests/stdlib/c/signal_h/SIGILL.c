//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/signal_h/SIGILL-d1.h"

// IWYU: SIGILL is defined in...*signal.h
void foo(void) { (void) SIGILL; }

/**** IWYU_SUMMARY

tests/stdlib/c/signal_h/SIGILL.c should add these lines:
#include <signal.h>

tests/stdlib/c/signal_h/SIGILL.c should remove these lines:
- #include "tests/stdlib/c/signal_h/SIGILL-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/signal_h/SIGILL.c:
#include <signal.h>  // for SIGILL

***** IWYU_SUMMARY */
