cmake_minimum_required(VERSION 3.3)
project(lec15 CXX)
include(.eecs230/CMakeLists.txt)

add_test_program(pizza_test test/pizza_test.cpp src/pizza.cpp)
add_test_program(symbol_test test/symbol_test.cpp src/symbol.cpp)

add_program(renderable_main src/renderable_main.cpp src/renderable.cpp)
target_link_libraries(renderable_main graphics)

add_test_program(restorer_test test/restorer_test.cpp src/restorer.h)
