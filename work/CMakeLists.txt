include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(exercise-template exercise-template.cpp chapter8/RainVector.cpp chapter8/RainVector.h chapter9/Exception.cpp chapter9/Exception.h chapter9/main.cpp)
add_subdirectory(chapter7)
add_subdirectory(chapter8)
add_subdirectory(chapter9)