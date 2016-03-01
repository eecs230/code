#pragma once

#include "sample.h"
#include "raster/color32.h"

#include <cstddef>

namespace graphics
{

class color
{
public:
    color() noexcept; // transparent
    color(sample red, sample green, sample blue,
          sample alpha = sample::ONE) noexcept;

    color(graphics::color32) noexcept;
    operator graphics::color32() const noexcept;

    static color const transparent;
    static color const white;
    static color const black;

    sample red()   const noexcept { return red_;   }
    sample green() const noexcept { return green_; }
    sample blue()  const noexcept { return blue_;  }
    sample alpha() const noexcept { return alpha_; }

private:
    sample red_, green_, blue_, alpha_;
};

color grayscale(const color&) noexcept;
color overlay(const color& foreground, const color& background) noexcept;
color interpolate(const color& a, sample weight, const color& b) noexcept;

} // namespace graphics
