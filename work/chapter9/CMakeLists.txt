cmake_minimum_required(VERSION 3.8)
project(chapter9)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES Exception.cpp Exception.h main_one.cpp)
add_executable(chapter9 ${SOURCE_FILES})
add_executable(chapter9-1 main_bad_alloc.cpp)