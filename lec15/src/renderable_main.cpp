#include "renderable.h"
#include <cmath>

using namespace graphics;
using namespace sampleable;

int main()
{
    affinity rotate_rect = affinity::rotation(M_PI_4).centered_on(400, 400);

    auto bg = Renderable::everything({.5, .5, .5});
    auto circ1 = Renderable::circle({250, 285}, 200, {1, 1, 0, .5});
    auto circ2 = Renderable::circle({550, 285}, 200, {0, 1, 1, .5});
    auto circ3 = Renderable::circle({400, 515}, 200, {1, 0, 1, .5});
    auto rect = Renderable::rectangle(bbox<double>(150, 650, 650, 150),
                                      Color::white).transform(rotate_rect);
    auto scene = overlay({ bg, rect, circ1, circ2, circ3 });

    raster r(800, 800);
    scene.render(r);
    r.write_bmp("out.bmp");
}