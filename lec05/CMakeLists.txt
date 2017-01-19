cmake_minimum_required(VERSION 3.3)
project(lec05 CXX)
include(.eecs230/CMakeLists.txt)

add_program(grading
        src/grading_main.cpp
        src/grading.cpp)

add_test_program(grading_test
        test/grading_test.cpp
        src/grading.cpp)
