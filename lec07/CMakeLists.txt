cmake_minimum_required(VERSION 3.3)
project(lec08 CXX)
include(.eecs230/CMakeLists.txt)

add_test_program(factorial_test
        test/factorial_test.cpp src/factorial.h src/factorial.cpp)

add_test_program(geometry_test
        test/geometry_test.cpp src/geometry.h src/geometry.cpp )

add_test_program(Time_of_day_test
        test/time_of_day_test.cpp src/Time_of_day.h src/Time_of_day.cpp)
