//===-- gen_stdlib_tests.py generated file ----------------------*- C++ -*-===//
//
// This file was generated automatically by
// tests/stdlib/gen_stdlib_tests.py, DO NOT EDIT!
//
// Generated from cppreference offline HTML book (modified on 2023-08-11).
//===----------------------------------------------------------------------===//
// IWYU_ARGS: -I.

#include "tests/stdlib/c/threads_h/thread_local-d1.h"

// IWYU: thread_local is defined in...*threads.h
thread_local char tlc;

/**** IWYU_SUMMARY

tests/stdlib/c/threads_h/thread_local.c should add these lines:
#include <threads.h>

tests/stdlib/c/threads_h/thread_local.c should remove these lines:
- #include "tests/stdlib/c/threads_h/thread_local-d1.h"  // lines XX-XX

The full include-list for tests/stdlib/c/threads_h/thread_local.c:
#include <threads.h>  // for thread_local

***** IWYU_SUMMARY */
