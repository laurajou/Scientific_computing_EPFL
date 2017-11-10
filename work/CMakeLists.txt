include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(exercise-template exercise-template.cpp chapter8/RainVector.cpp chapter8/RainVector.h)
add_subdirectory(chapter7)
add_subdirectory(chapter8)