cmake_minimum_required(VERSION 3.3)
project(17ub CXX)
include(.eecs230/CMakeLists.txt)

add_program(div_mul div_mul.cpp)
add_program(int_max int_max.cpp)
add_program(left_shift left_shift.cpp)
add_program(null_check null_check.cpp)
add_program(uninitialized uninitialized.cpp)
add_program(array array.cpp)

add_program(iterator iterator.cpp)
