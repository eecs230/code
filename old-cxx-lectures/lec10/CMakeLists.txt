cmake_minimum_required(VERSION 3.3)
project(lec10 CXX)
include(.eecs230/CMakeLists.txt)

add_test_program(Int_vector_tests
        test/Int_vector_tests.cpp
        src/Int_vector.cpp src/Int_vector.h)
