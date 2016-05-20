// Example that renders several circles under various transformations.

#include "Background.h"
#include "Circle.h"
#include "Fill.h"
#include "Gradient.h"
#include "Opacity.h"
#include "Overlay.h"
#include "Transform.h"

#include "render.h"

#include <cstdlib>

using namespace graphics;

constexpr size_t width{800}, height{600};

int main()
{
    raster raster(width, height);

//    auto c1s = circle({300, 225}, 200);
//    auto c1  = gradient(c1s, color{1, 1, 0}, color{0, 1, 0, .2}, Circular{});
//
//    auto c2  = opacity(gradient(circle({500, 225}, 200),
//                                color{.5, 0, 0}, color::black,
//                                Circular{}, Sinusoidal{10, .25}),
//                       0.5);
//
//    auto c3  = transform(opacity(gradient(circle({400, 381}, 200),
//                                          color{0, 0, 1}, color::white,
//                                          Vertical{}), 0.7),
//                         affinity::rotation(10)(affinity::dilation(2, .25))
//                                 .centered_on(400, 381));
//
//    auto drawing = overlay({ c3, c2, c1, background(color::black) });

    auto red     = fill(circle({100, 100}, 50), color{1, 0, 0});
    auto green   = fill(circle({250, 100}, 50), color{0, 1, 0});
    auto blue    = fill(circle({400, 100}, 50), color{0, 0, 1});

    auto drawing = overlay({red, green, blue, background(color::white)});

    render(*drawing, raster);

    raster.write_bmp("circles.bmp");
    system("open circles.bmp");
}
