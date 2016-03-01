#include "Shape.h"

Shape::Shape(const B_box& box, const Shape::color& color)
        : bounding_box_ (box), color_{color}
{ }

const B_box& Shape::get_bounding_box() const
{
    return bounding_box_;
}

Shape::color Shape::color_at(Point point) const
{
    if (contains(point))
        return color_;
    else
        return graphics::F_color::transparent;
}

Shape::~Shape() { }

