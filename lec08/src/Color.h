#pragma once

#include "sample.h"

#include <iostream>

namespace graphics
{

class Color
{
public:
    Color(); // transparent
    Color(sample red, sample green, sample blue,
          sample alpha = sample::one);

    static Color const transparent;
    static Color const white;
    static Color const black;

    sample red()   const { return red_;   }
    sample green() const { return green_; }
    sample blue()  const { return blue_;  }
    sample alpha() const { return alpha_; }

private:
    sample red_, green_, blue_, alpha_;
    // Invariant: if alpha_ == 0 then red_ == green_ == blue_ == 0
};

Color grayscale(const Color&);
Color overlay(const Color& foreground, const Color& background);
Color interpolate(const Color& a, sample weight, const Color& b);

bool operator==(const Color&, const Color&);
bool operator!=(const Color&, const Color&);

std::ostream& operator<<(std::ostream&, const Color&);

} // namespace graphics
