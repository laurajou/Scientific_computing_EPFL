include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# The next lines represent a list of all the executables in the folder (chapter)
# There is typically one executable per exercise.
# As you solve exercises, you need to add them here.
# The syntax is add_executable(executable_name source_file_name)

add_executable(ch-09-ex-01-solution ch-09-ex-01-solution.cpp Exception.cpp
               FileNotOpenException.cpp)
add_executable(ch-09-ex-02-solution ch-09-ex-02-solution.cpp)
add_executable(ch-09-ex-03-solution ch-09-ex-03-solution.cpp
               AbstractOdeSolver.cpp ForwardEulerSolver.cpp
               RungeKuttaSolver.cpp Exception.cpp)

file(COPY test.dat DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(stl-exercise.solution stl-exercise.solution.cpp)
	     
