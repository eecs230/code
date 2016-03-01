#include "Background.h"
#include "Circle.h"
#include "Fill.h"
#include "Gradient.h"
#include "Opacity.h"
#include "Overlay.h"
#include "Polygon.h"
#include "Transform.h"

#include "render.h"

#include <graphics.h>

#include <cstdlib>

using namespace graphics;

constexpr size_t width{800}, height{600};

int main()
{
    raster raster(width, height);

    Circle c1s({300, 225}, 200);
    Gradient c1(c1s, color{1, 1, 0}, color{0, 1, 0, .2}, Circular{});

    Circle c2s({500, 225}, 200);
    Gradient c2f(c2s, color{.5, 0, 0}, color::black,
                 Circular{}, Sinusoidal{10, .25});
    Opacity c2(c2f, 0.5);

    Circle c3s({400, 381}, 200);
    Gradient c3f(c3s, color{0, 0, 6}, color::white, Vertical{});
    Opacity c3t(c3f, 0.7);
    Transform c3(c3t, affinity::rotation(10)(affinity::dilation(2, .25))
            .centered_on(400, 381));

    Overlay a(c1, c2);
    Overlay b(c3, a);

    simple_render(Overlay(b, Background(color::white)), raster);

    raster.write_bmp("circles.bmp");
    system("open circles.bmp");
}
