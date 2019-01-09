cmake_minimum_required(VERSION 3.3)
project(lec08 CXX)
include(.eecs230/CMakeLists.txt)

add_test_program(rational_test
        test/rational_test.cpp
        src/Rational.cpp)

add_test_program(vending_machine_test
        test/vending_machine_test.cpp
        src/Vending_machine.cpp)

