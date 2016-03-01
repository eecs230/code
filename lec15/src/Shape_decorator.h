#pragma once

#include "Shape.h"

class Shape_decorator : public Shape
{
public:
    Shape_decorator(const Shape&);
    Shape_decorator(const Shape&, bbox);

    bool contains(posn) const;
    color color_at(posn) const;

private:
    const Shape& base_;
};
