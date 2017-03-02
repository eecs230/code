#pragma once

#include "color.h"

namespace graphics
{

class color_blender
{
public:
    color_blender() noexcept;

    color_blender& add(sample::repr, const Color&) noexcept;
    Color get() const noexcept;

private:
    sample::repr red_    = 0;
    sample::repr green_  = 0;
    sample::repr blue_   = 0;
    sample::repr alpha_  = 0;
    sample::repr weight_ = 0;
};

color_blender& operator<<(color_blender&, const Color&) noexcept;

} // end namespace graphics
