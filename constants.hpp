#pragma once

#include <string>

template <class T, T&(*init_fun)()>
struct eager_initializer {
    static T& instance;
};
template <class T, T&(*init_fun)()>
T& eager_initializer<T, init_fun>::instance = init_fun();

inline std::string& GetFoo() {
  static std::string foo = "I'm a string";
  return foo;
}
inline std::string& foo() { return eager_initializer<std::string, &GetFoo>::instance; }

__attribute__((noinline)) inline std::string MakeBar() { return foo() + " too"; }

inline std::string& GetBar() {
  static std::string bar = MakeBar();
  return bar;
}
static std::string& bar = GetBar();
