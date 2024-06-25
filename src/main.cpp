//
// C++20 CLI Template
// Copyright (c) Moon Happy / Phillip Cooper.
//
// This code is licensed under MIT license (see LICENSE for details)
//

// #include <iostream>
#include <CLI/CLI.hpp>
#include "hello.hpp"

int main(int argc, char * argv[]) {
    CLI::App app{"App description"};
    argv = app.ensure_utf8(argv);

    std::string filename = "default";
    app.add_option("-f,--file", filename, hello_world());

    CLI11_PARSE(app, argc, argv);

    return 0;
}
