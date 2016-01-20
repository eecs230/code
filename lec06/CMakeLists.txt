cmake_minimum_required(VERSION 3.3)
project(lec06 CXX)
include(.eecs230/CMakeLists.txt)

add_program(grades src/grades.cpp)
add_program(drop src/drop.cpp)
