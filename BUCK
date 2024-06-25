#
# C++20 CLI Template
# Copyright (c) Moon Happy / Phillip Cooper.
#
# This code is licensed under MIT license (see LICENSE for details)
#

# Buck2: https://buck2.build/

load('//:subdir_glob.bzl', 'subdir_glob')


########################################
# Fetch GoogleTest for unit tests
# ATTRIBUTION: https://github.com/facebook/buck2/issues/293
########################################
cxx_library(
    name = "gtest",
    header_namespace = "gtest",
    include_directories= [
        ("lib/googletest/googletest/"),
        ("lib/googletest/googletest/include/"),
        ("lib/googletest/googlemock/"),
        ("lib/googletest/googlemock/include/"),
    ],
    headers = subdir_glob([
        ("lib/googletest/googletest/include/gtest/", "**/*.h"),
        ("lib/googletest/googlemock/include/gmock/", "**/*.h"),
    ]),
    srcs = glob(
        include = [
            "lib/googletest/googletest/src/*.cc",
            "lib/googletest/googlemock/src/*.cc",
        ],
        exclude = [
            "lib/googletest/googletest/src/gtest-all.cc",
            # "lib/googletest/googletest/src/gtest_main.cc",
            "lib/googletest/googlemock/src/gmock-all.cc",
            "lib/googletest/googlemock/src/gmock_main.cc",
        ],
    ),
    exported_headers = subdir_glob([
        ("lib/googletest/googletest/include/gtest/", "**/*.h"),
        ("lib/googletest/googlemock/include/gmock/", "**/*.h"),
    ]),
    # platform_linker_flags = [
    #   ('android', []),
    #   ('', ['-lpthread']),
    # ],
    visibility = ["PUBLIC"],
    compiler_flags = ["-std=c++20"],
    # visibility = [
    #   '//test/...',
    # ],
)

########################################
# Declare build target for executable
########################################
cxx_binary(
    name = "template_cpp",
    compiler_flags = ["-std=c++20"],
    include_directories = ["include", "lib/CLI11/include/"],
    headers = glob(["*.hpp"]),
    srcs = glob(["src/*.cpp"]),
    link_style = "static",
)


########################################
# Declare test target for executable
# TODO: Change to cxx_test when possible
########################################
cxx_binary(
    name = "template_test",
    compiler_flags = ["-std=c++20"],
    include_directories = ["include"],
    headers = glob(["*.hpp"]),
    srcs = glob(
        ["src/*.cpp", "test/*.cpp"],
        exclude = ["src/main.cpp"]
    ),
    deps = [
        "//:gtest"
    ]
)
