cmake_minimum_required(VERSION 3.8)
project(chapter6)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp ComplexNumber.cpp ComplexNumber.hpp)
add_executable(chapter6 ${SOURCE_FILES})