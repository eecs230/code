cmake_minimum_required(VERSION 3.3)
project(lec13 CXX)
include(.eecs230/CMakeLists.txt)

add_test_program(Bst_tests
        test/Bst_tests.cpp
        src/Bst.cpp
        src/Bst.h)
