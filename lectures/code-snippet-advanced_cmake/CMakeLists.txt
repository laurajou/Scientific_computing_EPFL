cmake_minimum_required(VERSION 3.8)
project(advanced_cmake)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(advanced_cmake ${SOURCE_FILES})


file(COPY "test.txt" DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

include_directories("/usr/include")
target_link_libraries(advanced_cmake z)

# provide complete path to the library
# target_link_libraries(advanced_cmake "/complete/path/to/external/liblibrary.so)


 file(COPY "Doxyfile" DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
 find_package(Doxygen)
 add_custom_target(doc
         ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
         COMMENT "Generating API documentation with Doxygen" VERBATIM
         )
