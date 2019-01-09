#include "Color.h"

namespace graphics
{

// using graphics::color32;

Color::Color() : Color{0, 0, 0, 0}
{ }

Color::Color(sample red, sample green, sample blue, sample alpha)
        : red_{red}, green_{green}, blue_{blue}, alpha_{alpha}
{
    if (alpha == sample::zero) red_ = green_ = blue_ = sample::zero;
}

Color const Color::transparent{0, 0, 0, 0};
Color const Color::white{1, 1, 1, 1};
Color const Color::black{0, 0, 0, 1};

bool opaque(const Color& c)
{
    return c.alpha() == sample::one;
}

bool transparent(const Color& c)
{
    return c.alpha() == sample::zero;
}

Color grayscale(const Color& c)
{
    auto red   = c.red()   * .33333;
    auto green = c.green() * .33334;
    auto blue  = c.blue()  * .33333;
    auto intensity = red + green + blue;

    return {intensity, intensity, intensity, c.alpha()};
}

Color overlay(const Color& fg, const Color& bg)
{
    if (opaque(fg) || transparent(bg)) return fg;
    if (transparent(fg)) return bg;

    return interpolate(bg, fg.alpha(), Color{fg.red(), fg.green(), fg.blue()});
}

Color interpolate(const Color& a, sample weight, const Color& b)
{
    auto pre_red   =
            interpolate(a.alpha() * a.red(), weight, b.alpha() * b.red());
    auto pre_green =
            interpolate(a.alpha() * a.green(), weight, b.alpha() * b.green());
    auto pre_blue  =
            interpolate(a.alpha() * a.blue(), weight, b.alpha() * b.blue());
    auto new_alpha = interpolate(a.alpha(), weight, b.alpha());

    return {pre_red / new_alpha,
            pre_green / new_alpha,
            pre_blue / new_alpha,
            new_alpha};
}

bool operator==(const Color& a, const Color& b)
{
    return a.red() == b.red() &&
            a.green() == b.green() &&
            a.blue() == b.blue() &&
            a.alpha() == b.alpha();
}

bool operator!=(const Color& a, const Color& b)
{
    return !(a == b);
}

std::ostream& operator<<(std::ostream& os, const Color& c)
{
    if (c.alpha() == 0) {
        return os << "RGB("
                  << c.red() << ','
                  << c.green() << ','
                  << c.blue() << ')';
    } else {
        return os << "RGBA("
                  << c.red() << ','
                  << c.green() << ','
                  << c.blue() << ','
                  << c.alpha() << ')';
    }
}

} // end namespace graphics
