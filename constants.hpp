#pragma once

#include <iostream>
#include <string>

inline std::string& GetFoo() {
  static std::string foo = "I'm a string";
  return foo;
}
static std::string& foo = GetFoo();

__attribute__((noinline)) inline std::string MakeBar(std::string const & x) { return x + " too"; }

inline std::string& GetBar() {
  static std::string bar = MakeBar(foo);
  return bar;
}
static std::string& bar = GetBar();
