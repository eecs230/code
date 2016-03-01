#include "raster/Raster.h"

using namespace raster;

int main()
{
    Raster r(800, 600, color{255, 0, 0});
    r.write_bmp("red.bmp");
}
