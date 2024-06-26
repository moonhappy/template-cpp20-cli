#
# C++20 CLI Template
# Copyright (c) Moon Happy / Phillip Cooper.
#
# This code is licensed under MIT license (see LICENSE for details)
#

cmake_minimum_required(VERSION 3.5)
project(TemplateCpp VERSION 0.1.0 LANGUAGES CXX)


########################################
# Set C++ compiler options
########################################
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


########################################
# Set code search paths
########################################
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/lib/CLI11/include
)
file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/include/*.hpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)


########################################
# Declare build target for executable
########################################
add_executable(template_cpp ${all_SRCS})


########################################
# Declare unit test target (GoogleTest)
########################################
enable_testing()
include(GoogleTest)
add_subdirectory("${PROJECT_SOURCE_DIR}/lib/googletest")
file(GLOB test_SRCS
    "${PROJECT_SOURCE_DIR}/include/*.hpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/test/*.cpp"
)
list(REMOVE_ITEM test_SRCS "${PROJECT_SOURCE_DIR}/src/main.cpp")

add_executable(template_test ${test_SRCS})

target_link_libraries(template_test GTest::gtest_main)


gtest_discover_tests(template_test)
