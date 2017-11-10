cmake_minimum_required(VERSION 3.8)
project(chapter8)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES RainVector.cpp RainVector.h AbsoluteValue.h)
add_executable(chapter8 ${SOURCE_FILES})