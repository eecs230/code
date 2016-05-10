cmake_minimum_required(VERSION 3.3)
project(lec11 CXX)
include(.eecs230/CMakeLists.txt)

add_test_program(Cons_list_tests
        test/Cons_list_tests.cpp
        src/Cons_list.cpp src/Cons_list.h)
