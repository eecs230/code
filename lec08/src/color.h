#pragma once

#include "sample.h"

#include <cstddef>
#include <cstdint>

namespace graphics
{

class color
{
public:
    color(); // transparent
    color(sample red, sample green, sample blue,
          sample alpha = sample::one);

    static color const transparent;
    static color const white;
    static color const black;

    sample red()   const { return red_;   }
    sample green() const { return green_; }
    sample blue()  const { return blue_;  }
    sample alpha() const { return alpha_; }

private:
    sample red_, green_, blue_, alpha_;
};

color grayscale(const color&);
color overlay(const color& foreground, const color& background);
color interpolate(const color& a, sample weight, const color& b);

} // namespace graphics
