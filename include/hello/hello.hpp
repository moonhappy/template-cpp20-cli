//
// C++20 CLI Template
// Copyright (c) Phillip Cooper | https://moonhappy.io
//
// This code is licensed under MIT license (see LICENSE for details)
//

#include <string>

#ifndef HELLO_HELLO_HPP_
#define HELLO_HELLO_HPP_


consteval int add(int a, int b) { return a+b; }
constexpr int r = add(100, 300);

std::string hello_world();


#endif  // HELLO_HELLO_HPP_

