#include "Gradient.h"

Gradient::Gradient(const Shape& base, color start, color end,
                   const Projector& projector,
                   const Modulator& modulator)
        : Shape_decorator{base}
        , start_{start}
        , end_{end}
        , projector_{projector}
        , modulator_{modulator}
{ }

// Interpolates a color between start_ and end_, using the modulator
// to alter the weight.
Shape::color Gradient::color_at(sample weight) const
{
    return interpolate(start_, modulator_.modulate(weight), end_);
}

// Computes the color at an abstract (unit square) position by
// projecting it to 1-D and then delegating to color_at(sample).
Shape::color Gradient::color_at(sample x, sample y) const
{
    return color_at(projector_.project(x, y));
}

graphics::color Gradient::color_at(posn point) const
{
    if (contains(point)) {
        // Maps the bounding box to the unit square
        sample x = (point.x - get_bbox().left()) / get_bbox().width();
        sample y = (point.y - get_bbox().top()) / get_bbox().height();

        return color_at(x, y);
    } else {
        return color::transparent;
    }
}
