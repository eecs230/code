#pragma once

#include "Coord.h"
#include <graphics.h>

class Shape
{
public:
    using color = graphics::F_color;

    Shape(const B_box&, const color& = color::black);

    const B_box& get_bounding_box() const;

    virtual bool contains(Point) const = 0;
    virtual color color_at(Point) const;

    virtual ~Shape();

private:
    B_box bounding_box_;
    color color_;
};
