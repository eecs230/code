cmake_minimum_required(VERSION 3.3)
project(lec08 CXX)
include(.eecs230/CMakeLists.txt)

add_test_program(factorial test/factorial.cpp src/factorial.h src/factorial.cpp)
add_test_program(geometry test/geometry.cpp src/geometry.h src/geometry.cpp)
