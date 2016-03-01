#include "render.h"

void render(const Shape& shape, raster::Raster& raster, size_t antialias)
{
    for (int y = 0; y < raster.height(); ++y) {
        for (int x = 0; x < raster.width(); ++x) {
            if (shape.contains({(double)x, (double)y})) {
                raster.at(x, y) = raster::color::black;
            }
        }
    }
}
