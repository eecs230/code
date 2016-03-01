cmake_minimum_required(VERSION 3.3)
project(lec15 CXX)
include(.eecs230/CMakeLists.txt)

set(COLOR src/graphics/raster/color.cpp src/graphics/raster/color.h)
set(RASTER src/graphics/raster/Raster.cpp src/graphics/raster/Raster.h
        src/graphics/raster/bmp_header.cpp src/graphics/raster/bmp_header.h
        ${COLOR})

add_test_program(color test/color.cpp ${COLOR})

add_program(red test/integration/red.cpp ${RASTER})
