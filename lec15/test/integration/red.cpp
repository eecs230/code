#include "graphics.h"

using namespace graphics;

int main()
{
    raster r(800, 600, color{255, 0, 0});
    r.write_bmp("/Users/tov/Desktop/red.bmp");
}

