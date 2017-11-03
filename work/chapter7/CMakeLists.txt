cmake_minimum_required(VERSION 3.8)
project(chapter7)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Student.cpp Student.h AbstractOdeSolver.h AbstractOdeSolver.cpp)
add_executable(chapter7 ${SOURCE_FILES})
