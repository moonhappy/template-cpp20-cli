//
// C++20 CLI Template
// Copyright (c) Moon Happy / Phillip Cooper.
//
// This code is licensed under MIT license (see LICENSE for details)
//

// ATTRIBUTION: 
// https://github.com/facebook/buck2/tree/main/examples/hello_world
// Copyright (c) Meta Platforms, Inc. and affiliates.

#include <sstream>
#include "hello.hpp"

consteval int add(int a, int b) { return a+b; }
constexpr int r = add(100, 300);

std::string hello_world() {
    std::ostringstream ss;
    ss << "Hello, World! r = " << r;
    return ss.str();
}
