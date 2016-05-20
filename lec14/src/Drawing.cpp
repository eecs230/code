#include "Drawing.h"

Drawing::Drawing(const bbox& box, const Drawing::color& color)
        : bbox_(box), color_{color}
{ }

const Drawing::bbox& Drawing::get_bbox() const
{
    return bbox_;
}

Drawing::color Drawing::color_at(posn point) const
{
    if (contains(point))
        return color_;
    else
        return graphics::color::transparent;
}

Drawing::~Drawing() { }

