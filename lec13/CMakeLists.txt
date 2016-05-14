cmake_minimum_required(VERSION 3.3)
project(lec13 CXX)
include(.eecs230/CMakeLists.txt)

add_test_program(Bst_tests
    test/Bst_tests.cpp
        src/Bst_set.h)

add_test_program(Int_bst_tests
        test/Int_bst_tests.cpp
        src/Int_bst_set.cpp
        src/Int_bst_set.h)

add_test_program(String_bst_tests
        test/String_bst_tests.cpp
        src/String_bst_set.cpp
        src/String_bst_set.h)

add_test_program(Cons_list_tests
        test/Cons_list_tests.cpp
        src/Cons_list.cpp
        src/Cons_list.h)
