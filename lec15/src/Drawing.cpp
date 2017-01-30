#include "Drawing.h"

Drawing::Drawing(const bbox& box)
        : bbox_(box)
{ }

const Drawing::bbox& Drawing::get_bbox() const
{
    return bbox_;
}

Drawing::color Drawing::color_at(posn point) const
{
    if (contains(point))
        return color::black;
    else
        return color::transparent;
}

Drawing::~Drawing() { }

