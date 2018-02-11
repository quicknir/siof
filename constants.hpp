#pragma once

#include <iostream>
#include <string>

inline std::string& GetFoo() {
  static std::string foo = "I'm a string";
  return foo;
}
static std::string& foo = GetFoo();

__attribute__((noinline)) inline std::string MakeBar() { return foo + " too"; }

inline std::string& GetBar() {
  static std::string bar = MakeBar();
  return bar;
}
static std::string& bar = GetBar();
