cmake_minimum_required(VERSION 3.3)
project(lec13 CXX)
include(.eecs230/CMakeLists.txt)

add_test_program(Int_double_pair_test
        test/Int_double_pair_test.cpp
        src/Int_double_pair.cpp)

add_test_program(Pair_test
        test/Pair_test.cpp
        src/Pair.h)

add_test_program(Int_vector_test
        test/Int_vector_test.cpp
        src/Int_vector.cpp)

add_test_program(String_vector_test
        test/String_vector_test.cpp
        src/String_vector.cpp)

add_test_program(String_int_dict_test
        test/String_int_dict_test.cpp
        src/String_int_dict.cpp)

add_test_program(Vector_test
        test/Vector_test.cpp
        src/Vector.h)

add_test_program(Dict_test
        test/Dict_test.cpp
        src/Dict.h
        src/Vector.h)
