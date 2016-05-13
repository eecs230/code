cmake_minimum_required(VERSION 3.3)
project(lec12 CXX)
include(.eecs230/CMakeLists.txt)

add_test_program(Bst_tests
        test/Bst_tests.cpp
        src/Bst_set.cpp
        src/Bst_set.h)
