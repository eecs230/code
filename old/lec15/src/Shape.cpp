#include "Shape.h"

Shape::Shape(const bbox& box, const Shape::color& color)
        : bbox_(box), color_{color}
{ }

const Shape::bbox& Shape::get_bbox() const
{
    return bbox_;
}

Shape::color Shape::color_at(posn point) const
{
    if (contains(point))
        return color_;
    else
        return graphics::color::transparent;
}

Shape::~Shape() { }

