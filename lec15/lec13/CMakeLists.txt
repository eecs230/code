cmake_minimum_required(VERSION 3.3)
project(lec13 CXX)
include(.eecs230/CMakeLists.txt)

add_test_program(Bst_set_tests
        test/Bst_set_tests.cpp
        src/Bst_set.h)

add_test_program(Bst_map_tests
        test/Bst_map_tests.cpp
        src/Bst_map.h)

add_test_program(Vector_tests
        test/Vector_tests.cpp
        src/Vector.h)

