cmake_minimum_required(VERSION 3.3)
project(lec08 CXX)
include(.eecs230/CMakeLists.txt)

add_test_program(rational1_test
        test/rational1_test.cpp
        src/Rational1.cpp)

add_test_program(rational2_test
        test/rational2_test.cpp
        src/Rational2.cpp)

add_test_program(vending_machine_test
        test/vending_machine_test.cpp
        src/Vending_machine.cpp)

add_test_program(graphics_test
        test/sample_test.cpp
        test/color_test.cpp
        src/sample.cpp
        src/Color.cpp)
