#pragma once

#include "sample.h"
#include "raster/color32.h"

#include <cstddef>

namespace graphics
{

class Color
{
public:
    Color() noexcept; // transparent
    Color(sample red, sample green, sample blue,
          sample alpha = sample::one) noexcept;

    static Color from_premixed_alpha(
            sample alpha_red, sample alpha_green,
            sample alpha_blue, sample alpha = sample::one) noexcept;

    Color(graphics::color32) noexcept;
    operator graphics::color32() const noexcept;

    static Color const transparent;
    static Color const white;
    static Color const black;

    sample alpha_red() const noexcept { return a_red_; }
    sample alpha_green() const noexcept { return a_green_; }
    sample alpha_blue() const noexcept { return a_blue_; }

    sample red()   const noexcept { return a_red_ / alpha_; }
    sample green() const noexcept { return a_green_ / alpha_; }
    sample blue()  const noexcept { return a_blue_ / alpha_;  }
    sample alpha() const noexcept { return alpha_; }

    bool is_opaque() const noexcept { return alpha_ == sample::one; }
    bool is_transparent() const noexcept { return alpha_ == sample::zero; }

private:
    sample a_red_, a_green_, a_blue_, alpha_;
};

Color overlay(const Color& foreground, const Color& background) noexcept;
Color interpolate(const Color& a, sample weight, const Color& b) noexcept;

class Partial_blend
{
    Partial_blend(Color left, sample weight);

    Color  left_;
    sample weight_;

    friend Partial_blend operator<(const Color&, sample);
    friend Color operator>(const Partial_blend&, const Color&);
};

Partial_blend operator<(const Color&, sample);
Color operator>(const Partial_blend&, const Color&);

} // namespace graphics
