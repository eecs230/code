#include "Polygon.h"
#include "Circle.h"
#include "Fill.h"
#include "Opacity.h"
#include "Overlay.h"
#include "Frame.h"

#include "render.h"

#include <graphics.h>

using namespace graphics;

constexpr size_t width{800}, height{600};

int main()
{
    raster raster(width, height);


    Polygon p{{100, 50}, {200, 83}, {250, 600}, {300, 117}, {400, 150},
                     {700, 50}, {700, 350}, {400, 500}, {100, 350}};
    Fill q(p, color{1, 0, 0});

    Circle r({200, 300}, 100);
    Fill s(r, color{0, 0.5, 0});
    Opacity t(s, sample{0.5});

    Overlay z(t, q);

    render(Overlay(z, Frame()), raster);

    raster.write_bmp("polygon.bmp");
}
