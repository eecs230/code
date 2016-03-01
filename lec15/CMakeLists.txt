cmake_minimum_required(VERSION 3.3)
project(lec15 CXX)
include(.eecs230/CMakeLists.txt)

add_program(red test/integration/red.cpp)
target_link_libraries(red graphics)

set(SHAPES
        src/Coord.h
        src/Shape.h
        src/Shape.cpp
        src/Circle.h
        src/Circle.cpp
        src/Polygon.h
        src/Polygon.cpp
        src/Rectangle.h
        src/Rectangle.cpp
        src/Fill.h
        src/Fill.cpp
        src/Background.h
        src/Background.cpp
        src/Overlay.h
        src/Overlay.cpp
        src/Shape_decorator.h
        src/Shape_decorator.cpp
        src/Opacity.h
        src/Opacity.cpp
        src/Transform.h
        src/Transform.cpp
        src/Gradient.h
        src/Gradient.cpp
        src/render.h
        src/render.cpp
        )

add_program(circles test/integration/circles.cpp ${SHAPES})
target_link_libraries(circles graphics)
