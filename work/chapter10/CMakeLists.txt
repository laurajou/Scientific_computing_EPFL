cmake_minimum_required(VERSION 3.8)
project(chapter10)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES LinearSystem.cpp LinearSystem.hpp Matrix.cpp Matrix.hpp Vector.cpp Vector.hpp)
add_executable(chapter10 ${SOURCE_FILES})
