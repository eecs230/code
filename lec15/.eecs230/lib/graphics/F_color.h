#pragma once

#include "sample.h"
#include "raster/color.h"

#include <cstddef>

namespace graphics
{

class F_color
{
public:
    F_color() noexcept; // transparent
    F_color(sample red, sample green, sample blue,
            sample alpha = sample::ONE) noexcept;
    F_color(double red, double green, double blue, double alpha = 1.0) noexcept;

    F_color(raster::color) noexcept;
    operator raster::color() noexcept;

    static F_color const transparent;
    static F_color const white;
    static F_color const black;

    sample red()   const noexcept { return red_;   }
    sample green() const noexcept { return green_; }
    sample blue()  const noexcept { return blue_;  }
    sample alpha() const noexcept { return alpha_; }

private:
    sample red_, green_, blue_, alpha_;
};

F_color grayscale(const F_color&) noexcept;
F_color overlay(const F_color& foreground, const F_color& background) noexcept;
F_color interpolate(const F_color& a, double weight, const F_color& b) noexcept;

} // namespace graphics
