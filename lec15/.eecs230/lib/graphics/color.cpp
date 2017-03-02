#include "color.h"

namespace graphics
{

using graphics::color32;

Color::Color() noexcept : Color{0, 0, 0, 0}
{ }

Color::Color(sample red, sample green, sample blue, sample alpha) noexcept
        : a_red_{red * alpha},
          a_green_{green * alpha},
          a_blue_{blue * alpha},
          alpha_{alpha}
{ }

Color Color::from_premixed_alpha(
        sample alpha_red, sample alpha_green,
        sample alpha_blue, sample alpha) noexcept
{
    Color result;

    result.a_red_ = alpha_red;
    result.a_green_ = alpha_green;
    result.a_blue_ = alpha_blue;
    result.alpha_ = alpha;

    return result;
}

static sample to_sample(color32::byte b) noexcept
{
    return sample{b / static_cast<sample::repr>(color32::BYTE_MAX)};
}

Color::Color(color32 c) noexcept
        : Color{to_sample(c.red()),
                to_sample(c.green()),
                to_sample(c.blue()),
                to_sample(c.alpha())}
{ }

static color32::byte to_byte(sample s) noexcept
{
    return static_cast<color32::byte>(color32::BYTE_MAX * s.value());
}

Color::operator graphics::color32() const noexcept
{
    return color32{to_byte(red()),
                   to_byte(green()),
                   to_byte(blue()),
                   to_byte(alpha())};
}

Color const Color::transparent{0, 0, 0, 0};
Color const Color::white{1, 1, 1};
Color const Color::black{0, 0, 0};

Color overlay(const Color& fg, const Color& bg) noexcept
{
    if (fg.is_opaque() || bg.is_transparent()) return fg;
    if (fg.is_transparent()) return bg;

    sample co_alpha  =  fg.alpha().invert();

    auto alpha_red   = fg.alpha_red()   + bg.alpha_red()   * co_alpha;
    auto alpha_green = fg.alpha_green() + bg.alpha_green() * co_alpha;
    auto alpha_blue  = fg.alpha_blue()  + bg.alpha_blue()  * co_alpha;
    auto alpha       = fg.alpha()       + bg.alpha()       * co_alpha;

    return Color::from_premixed_alpha(alpha_red, alpha_green, alpha_blue,
                                      alpha);
}

Color interpolate(const Color& a, sample weight, const Color& b)
noexcept
{
    auto alpha_red   = interpolate(a.alpha_red(),   weight, b.alpha_red());
    auto alpha_green = interpolate(a.alpha_green(), weight, b.alpha_green());
    auto alpha_blue  = interpolate(a.alpha_blue(),  weight, b.alpha_blue());
    auto alpha       = interpolate(a.alpha(),       weight, b.alpha());

    return Color::from_premixed_alpha(alpha_red, alpha_green, alpha_blue,
                                      alpha);
}

Partial_blend::Partial_blend(Color left, sample weight)
        : left_{left}, weight_{weight}
{ }

Partial_blend operator<(const Color& left, sample factor)
{
    return Partial_blend{left, factor};
}

Color operator>(const Partial_blend& pb, const Color& right)
{
    return interpolate(pb.left_, pb.weight_, right);
}

} // end namespace graphics
