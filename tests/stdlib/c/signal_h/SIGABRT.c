//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/signal_h/SIGABRT-d1.h"

// IWYU: SIGABRT is defined in...*signal.h
void foo(void) { (void) SIGABRT; }

/**** IWYU_SUMMARY

tests/stdlib/c/signal_h/SIGABRT.c should add these lines:
#include <signal.h>

tests/stdlib/c/signal_h/SIGABRT.c should remove these lines:
- #include "tests/stdlib/c/signal_h/SIGABRT-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/signal_h/SIGABRT.c:
#include <signal.h>  // for SIGABRT

***** IWYU_SUMMARY */
