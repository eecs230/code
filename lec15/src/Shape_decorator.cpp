#include "Shape_decorator.h"

Shape_decorator::Shape_decorator(const Shape& base)
        : Shape_decorator{base, {base}}
{ }

Shape_decorator::Shape_decorator(const Shape& base, bbox box)
        : Shape{box}
        , base_{base}
{ }

bool Shape_decorator::contains(posn point) const
{
    return base_.contains(point);
}

graphics::color Shape_decorator::color_at(posn point) const
{
    return base_.color_at(point);
}
