cmake_minimum_required(VERSION 3.3)
project(lec11 CXX)
include(.eecs230/CMakeLists.txt)

add_test_program(Int_vector_tests
        test/Int_vector_tests.cpp
        src/Int_vector.cpp src/Int_vector.h)

add_test_program(Cons_list_tests
        test/Cons_list_tests.cpp
        src/Cons_list.cpp src/Cons_list.h)

add_test_program(String_list_tests
        test/String_list_tests.cpp
        src/String_list.cpp src/String_list.h)
