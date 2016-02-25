cmake_minimum_required(VERSION 3.3)
project(lec14 CXX)
include(.eecs230/CMakeLists.txt)

add_test_program(Bst_tests
    test/Bst_tests.cpp
    src/Bst.cpp
    src/Bst.h)

add_test_program(Int_vector_tests
    test/Int_vector_tests.cpp
    src/Int_vector.cpp
    src/Int_vector.h)
