#pragma once

#include "F_color.h"

namespace graphics
{

class Color_blender
{
public:
    Color_blender() noexcept;

    Color_blender& add(double weight, const F_color&) noexcept;
    operator F_color() const noexcept;

private:
    double red_    = 0;
    double green_  = 0;
    double blue_   = 0;
    double alpha_  = 0;
    double weight_ = 0;
};

Color_blender& operator<<(Color_blender&, const F_color&) noexcept;

} // end namespace graphics
