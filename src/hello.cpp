//
// C++20 CLI Template
// Copyright (c) Phillip Cooper | https://moonhappy.io
//
// This code is licensed under MIT license (see LICENSE for details)
//

#include <sstream>
#include "hello/hello.hpp"


std::string hello_world() {
    std::ostringstream ss;
    ss << "Hello, World! r = " << r;
    return ss.str();
}
