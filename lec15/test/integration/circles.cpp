#include "Polygon.h"
#include "Circle.h"
#include "Fill.h"
#include "Opacity.h"
#include "Overlay.h"
#include "Background.h"

#include "render.h"

#include <graphics.h>

using namespace graphics;

constexpr size_t width{800}, height{600};

int main()
{
    raster raster(width, height);

    Circle c1s({300, 225}, 200);
    Fill c1f(c1s, color{0, 1, 0});
    Opacity c1(c1f, 0.3);

    Circle c2s({500, 225}, 200);
    Fill c2f(c2s, color{1, 0, 0});
    Opacity c2(c2f, 0.3);

    Circle c3s({400, 381}, 200);
    Fill c3f(c3s, color{0, 0, 1});
    Opacity c3(c3f, 0.3);

    Overlay a(c1, c2);
    Overlay b(a, c3);

    render(Overlay(b, Background(color::black)), raster);

    raster.write_bmp("circles.bmp");
}
