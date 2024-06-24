//
// C++20 CLI Template
// Copyright (c) Moon Happy / Phillip Cooper.
//
// This code is licensed under MIT license (see LICENSE for details)
//

// ATTRIBUTION: 
// https://github.com/facebook/buck2/tree/main/examples/hello_world
// Copyright (c) Meta Platforms, Inc. and affiliates.

#include <iostream>

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

consteval int add(int a, int b) { return a+b; }
constexpr int r = add(100, 300);

DLLEXPORT void hello_world() {
    std::cout << "Hello, World! r = " << r << std::endl;
}
