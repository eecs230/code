#pragma once

#include "Shape.h"
#include "Shape_decorator.h"

// Applies an affine transformation (e.g., rotation, scaling, translation,
// shear) to a shape.
class Transform : public Shape_decorator
{
public:
    // Applies the given transformation to the base shape.
    Transform(const Shape& base, const graphics::affinity& transform);

    bool contains(posn) const;
    color color_at(posn) const;

private:
    // Stores the inverse of the desired transformation. See implementation
    // for explanation.
    graphics::affinity inv_;
};