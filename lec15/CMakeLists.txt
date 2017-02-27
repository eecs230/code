cmake_minimum_required(VERSION 3.3)
project(lec14 CXX)
include(.eecs230/CMakeLists.txt)

add_program(red test/red.cpp)
target_link_libraries(red graphics)

set(SHAPES
        src/Drawing.h
        src/Drawing.cpp
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
        src/Nothing.h
        src/Nothing.cpp
        src/Drawing_decorator.h
        src/Drawing_decorator.cpp
        src/Opacity.h
        src/Opacity.cpp
        src/Transform.h
        src/Transform.cpp
        src/Gradient.h
        src/Gradient.cpp
        src/Intersection.h
        src/Intersection.cpp
        src/Difference.h
        src/Difference.cpp
        src/render.h
        src/render.cpp
        )

add_program(circles test/circles.cpp ${SHAPES})
target_link_libraries(circles graphics)

add_program(box test/box.cpp ${SHAPES})
target_link_libraries(box graphics)
