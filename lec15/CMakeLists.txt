cmake_minimum_required(VERSION 3.3)
project(16patterns CXX)
include(.eecs230/CMakeLists.txt)

add_subdirectory(graphics_lib)
include_directories(graphics_lib)

add_test_program(pizza_test test/pizza_test.cpp src/pizza.cpp)

add_test_program(symbol_test test/symbol_test.cpp src/symbol.cpp)

add_program(renderable_main src/renderable_main.cpp src/renderable.cpp)
target_link_libraries(renderable_main graphics_lib)

add_test_program(restorer_test test/restorer_test.cpp src/restorer.h)

add_test_program(matcher_test test/matcher_test.cpp src/matcher.cpp)

add_test_program(vehicle
        src/vehicle.cpp
        src/vehicle_nested.h
        src/vehicle_mi.h
        src/vehicle_bridge.h)

add_test_program(bit_io_test
        test/bitio_test.cpp
        src/bit_io.cpp)
