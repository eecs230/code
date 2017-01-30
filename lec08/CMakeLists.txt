cmake_minimum_required(VERSION 3.3)
project(lec08 CXX)
include(.eecs230/CMakeLists.txt)

add_program(lec08 src/lec08.cpp
        src/color.cpp
        src/sample.cpp
        src/Vending_machine.cpp)
