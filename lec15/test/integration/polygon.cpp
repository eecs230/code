#include "Polygon.h"

#include <raster/Raster.h>
#include <render.h>

int main()
{
    Polygon p{{100, 50}, {200, 83}, {250, 600}, {300, 117}, {400, 150},
              {700, 50}, {700, 350}, {400, 500}, {100, 350}};
    raster::Raster raster(800, 600, raster::color::white);

    render(p, raster);

    raster.write_bmp("polygon.bmp");
}
