#include "Gradient.h"

Gradient::Gradient(const Shape& base, color start, color end,
                   const Shaper& shaper,
                   const Modulator& modulator)
        : Shape_decorator{base}
        , start_{start}
        , end_{end}
        , shaper_{shaper}
        , modulator_{modulator}
{ }

Shape::color Gradient::color_at(sample weight) const
{
    return interpolate(start_, modulator_.modulate(weight), end_);
}

Shape::color Gradient::color_at(sample x, sample y) const
{
    return color_at(shaper_.shape(x, y));
}

graphics::color Gradient::color_at(posn point) const
{
    sample x = (point.x - get_bbox().left()) / get_bbox().width();
    sample y = (point.y - get_bbox().top())  / get_bbox().height();
    return color_at(x, y);
}
