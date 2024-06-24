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
# Fetch GoogleTest for unit tests
########################################
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# - For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

########################################
# Declare unit test target (GoogleTest)
########################################
enable_testing()
file(GLOB test_SRCS
    "${PROJECT_SOURCE_DIR}/include/*.hpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/test/*.cpp"
)
list(REMOVE_ITEM test_SRCS "${PROJECT_SOURCE_DIR}/src/main.cpp")

add_executable(template_test ${test_SRCS})

target_link_libraries(template_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(template_test)
