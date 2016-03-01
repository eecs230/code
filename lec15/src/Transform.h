#pragma once

#include "Shape.h"

class Transform : public Shape
{
public:
    Transform(const Shape& base, const graphics::affinity& transform);

    bool contains(posn) const;
    color color_at(posn) const;

private:
    const Shape& base_;
    graphics::affinity inv_;
};