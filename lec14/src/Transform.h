#pragma once

#include "Drawing.h"
#include "Drawing_decorator.h"

// Applies an affine transformation (e.g., rotation, scaling, translation,
// shear) to a shape.
class Transform : public Drawing_decorator
{
public:
    // Applies the given transformation to the base shape.
    Transform(drawing_ptr, const graphics::affinity& transform);

    bool contains(posn) const;
    color color_at(posn) const;

private:
    // Stores the inverse of the desired transformation. See implementation
    // for explanation.
    graphics::affinity inv_;
};

drawing_ptr transform(drawing_ptr, const graphics::affinity&);