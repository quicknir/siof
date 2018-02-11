#pragma once

#include <iostream>
#include <string>

inline std::string& GetFoo() {
  static std::string foo = "I'm a string";
  return foo;
}
static std::string& foo = GetFoo();

inline std::string MakeBar() {
  std::cout << "foo has address " << &foo << "\n";
  return foo + " too";
}

inline std::string& GetBar() {
  static std::string bar = MakeBar();
  return bar;
}
static std::string& bar = GetBar();
