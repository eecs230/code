#include <cstdlib>
#include "graphics.h"

// Example that uses a raster directly, fills it with red, and writes it out
// to a .bmp file.

using namespace graphics;

int main()
{
    raster r(800, 600, color{255, 0, 0});

    for (size_t x = 100; x < 700; ++x) {
        for (size_t y = 100; y < 500; ++y) {
            r.at(x, y) = color::white;
        }
    }

    r.write_bmp("box.bmp");
    system("open box.bmp");
}

