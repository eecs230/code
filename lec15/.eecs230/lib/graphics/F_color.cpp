#include "F_color.h"

namespace graphics
{

using raster::color;

F_color::F_color() noexcept : F_color{0, 0, 0, 0}
{ }

F_color::F_color(sample red, sample green, sample blue, sample alpha) noexcept
        : red_{red}, green_{green}, blue_{blue}, alpha_{alpha}
{
    if (alpha == 0) red_ = green_ = blue_ = sample::ZERO;
}

F_color::F_color(double red, double green, double blue, double alpha) noexcept
        : F_color{sample{red}, sample{green}, sample{blue}, sample{alpha}}
{ }

static sample to_sample(color::byte b) noexcept
{
    return sample{b / static_cast<double>(color::BYTE_MAX)};
}

F_color::F_color(color c) noexcept
        : F_color{to_sample(c.red()),
                 to_sample(c.green()),
                 to_sample(c.blue()),
                 to_sample(c.alpha())}
{ }

static color::byte to_byte(sample s) noexcept
{
    return static_cast<color::byte>(color::BYTE_MAX * s.value());
}

F_color::operator color() noexcept
{
    return color{to_byte(red()),
                 to_byte(green()),
                 to_byte(blue()),
                 to_byte(alpha())};
}

F_color const F_color::transparent{0, 0, 0, 0};
F_color const F_color::white{1, 1, 1};
F_color const F_color::black{0, 0, 0};

bool opaque(const F_color& c) noexcept
{
    return c.alpha() == 1;
}

bool transparent(const F_color& c) noexcept
{
    return c.alpha() == 0;
}

F_color grayscale(const F_color& c) noexcept
{
    double lum = (c.red() + c.green() + c.blue()) / 3;
    return {lum, lum, lum, c.alpha()};
}

F_color overlay(const F_color& fg, const F_color& bg) noexcept
{
    if (fg.alpha() == 1 || bg.alpha() == 0) return fg;
    if (fg.alpha() == 0) return bg;

    return interpolate(bg, fg.alpha(), F_color{fg.red(), fg.green(), fg.blue()});
}

F_color interpolate(const F_color& a, double weight, const F_color& b)
noexcept
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
