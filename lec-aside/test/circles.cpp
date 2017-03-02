// Example that renders several circles under various transformations.

#include "Background.h"
#include "Circle.h"
#include "Fill.h"
#include "Gradient.h"
#include "Opacity.h"
#include "Overlay.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Transform.h"

#include "render.h"

#include <cstdlib>

using namespace graphics;

constexpr size_t width{800}, height{600};

int main()
{
    raster raster(width, height);

    auto red     = fill(circle({100, 100}, 100), color{1, 0, 0});
    auto green   = fill(circle({300, 100}, 100), color{0, 1, 0});
    auto blue    = fill(circle({500, 100}, 100), color{0, 0, 1});
    auto white   = fill(circle({700, 100}, 100), color{1, 1, 1});

    auto cyan    = fill(circle({100, 300}, 100), color{0, 1, 1});
    auto magenta = fill(circle({300, 300}, 100), color{1, 0, 1});
    auto yellow  = fill(regular_polygon({500, 300}, 100, 5), color{1, 1, 0});
    auto black   = fill(circle({700, 300}, 100), color{0, 0, 0});

    auto c1      = gradient(circle({100, 500}, 100),
                            color::black, color::white);
    auto c2      = gradient(circle({300, 500}, 100),
                            color::black, color::white,
                            Vertical{});
    auto c3      = gradient(circle({500, 500}, 100),
                            color::black, color::white,
                            Circular{});
    auto c4      = gradient(rectangle(400, 800, 600, 600),
                            color::black, color::white,
                            Circular{}, Sinusoidal{3});

    auto row1    = overlay({red, green, blue, white});
    auto row2    = overlay({cyan, magenta, yellow, black});
    auto row3    = overlay({c1, c2, c3, c4});

//    row2 = opacity(row2, 0.5);
//    row2 = transform(row2, affinity::rotation(.3).centered_on(400, 300));

    auto drawing = overlay({row2, row1, row3,
                            background(color{.5, .5, .5})});

    render(*drawing, raster);

    raster.write_bmp("circles.bmp");
    system("open circles.bmp"); // This works on OS X.
}
