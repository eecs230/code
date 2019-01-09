add_library(graphics_lib
        graphics.h
        geometry/affinity.h
        geometry/bbox.h
        geometry/posn.h
        raster/bmp_header.cpp
        raster/color32.cpp
        raster/raster.cpp
        color_blender.cpp
        color.cpp
        sample.cpp
        ../src/vehicle_nested.h)
set_property(TARGET graphics_lib PROPERTY CXX_STANDARD 14)
set_property(TARGET graphics_lib PROPERTY CXX_STANDARD_REQUIRED On)
