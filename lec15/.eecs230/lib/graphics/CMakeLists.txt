add_library(graphics
        geometry/affinity.h
        geometry/bounding_box.h
        geometry/posn.h
        geometry.h
        raster/bmp_header.cpp
        raster/bmp_header.h
        raster/color.cpp
        raster/color.h
        raster/graphics.cpp
        raster/Raster.h
        Color_blender.cpp
        Color_blender.h
        F_color.cpp
        F_color.h
        sample.cpp
        sample.h
        )
set_property(TARGET graphics PROPERTY CXX_STANDARD 11)
set_property(TARGET graphics PROPERTY CXX_STANDARD_REQUIRED On)
