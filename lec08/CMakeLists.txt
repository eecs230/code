cmake_minimum_required(VERSION 3.3)
project(lec08 CXX)
include(.eecs230/CMakeLists.txt)

add_test_program(Rational_test
    test/Rational_test
    src/Rational.h
    src/Rational.cpp)
