#include "graphics.h"

// Example that uses a raster directly, fills it with red, and writes it out
// to a .bmp file.

using namespace graphics;

int main()
{
    raster r(800, 600, color{255, 0, 0});
    r.write_bmp("red.bmp");
}

