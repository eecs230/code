#pragma once

#include "Shape.h"

// Abstract class for shapes the adapt/decorate another shape. This stores
// the shape-to-be-decorated and passes through function calls to it by
// default. Derive and override to change the behavior.
class Shape_decorator : public Shape
{
public:
    // Decorates the given shape, using its bounding box as the decorator's
    // bounding box.
    Shape_decorator(const Shape&);

    // Decorates the given shape, using the given bounding box.
    Shape_decorator(const Shape&, bbox);

    bool contains(posn) const;
    color color_at(posn) const;

private:
    const Shape& base_;
};
