cmake_minimum_required(VERSION 3.3)
project(lec15 CXX)
include(.eecs230/CMakeLists.txt)

add_test_program(pizza_test pizza_test.cpp pizza.cpp)
add_test_program(symbol_test symbol_test.cpp symbol.cpp)

add_program(sampleable_main sampleable_main.cpp sampleable.cpp)
target_link_libraries(sampleable_main graphics)
