cmake_minimum_required(VERSION 3.3)
project(lec09 CXX)
include(.eecs230/CMakeLists.txt)

add_program(lec09 src/lec09.cpp
        src/color.cpp
        src/sample.cpp
        src/Vending_machine.cpp)
