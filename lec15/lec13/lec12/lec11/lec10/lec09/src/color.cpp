#include "color.h"

namespace graphics
{

// using graphics::color32;

color::color() : color{0, 0, 0, 0}
{ }

color::color(sample red, sample green, sample blue, sample alpha)
        : red_{red}, green_{green}, blue_{blue}, alpha_{alpha}
{
    if (alpha == sample::zero) red_ = green_ = blue_ = sample::zero;
}

color const color::transparent{0, 0, 0, 0};
color const color::white{1, 1, 1, 1};
color const color::black{0, 0, 0, 1};

bool opaque(const color& c)
{
    return c.alpha() == sample::one;
}

bool transparent(const color& c)
{
    return c.alpha() == sample::zero;
}

color overlay(const color& fg, const color& bg)
{
    if (opaque(fg) || transparent(bg)) return fg;
    if (transparent(fg)) return bg;

    return interpolate(bg, fg.alpha(), color{fg.red(), fg.green(), fg.blue()});
}

color interpolate(const color& a, sample weight, const color& b)
{
    auto pre_red =
                 interpolate(a.alpha() * a.red(), weight, b.alpha() * b.red());
    auto pre_green =
                 interpolate(a.alpha() * a.green(), weight, b.alpha() * b.green());
    auto pre_blue =
                 interpolate(a.alpha() * a.blue(), weight, b.alpha() * b.blue());
    auto new_alpha = interpolate(a.alpha(), weight, b.alpha());

    return {pre_red / new_alpha, pre_green / new_alpha, pre_blue / new_alpha,
            new_alpha};
}

} // end namespace graphics
