#include "render.h"

#include <graphics.h>

void simple_render(const Drawing& shape, graphics::raster& raster)
{
    for (size_t y = 0; y < raster.height(); ++y) {
        for (size_t x = 0; x < raster.width(); ++x) {
            raster.at(x, y) = shape.color_at({x + .5, y + .5});
        }
    }
}

void render(const Drawing& shape, graphics::raster& raster, size_t antialias)
{
    for (size_t y = 0; y < raster.height(); ++y) {
        for (size_t x = 0; x < raster.width(); ++x) {
            graphics::color_blender cb;

            for (size_t i = 0; i < antialias; ++i) {
                for (size_t j = 0; j < antialias; ++j) {
                    Drawing::posn point{x + (i + 0.5) / antialias,
                                        y + (j + 0.5) / antialias};
                    cb << shape.color_at(point);
                }
            }

            raster.at(x, y) = cb.get();
        }
    }
}
