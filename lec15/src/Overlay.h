#pragma once

#include "Shape.h"

// Composes two shapes by overlaying one over the other.
class Overlay : public Shape
{
public:
    // Places `over` over `under`.
    Overlay(const Shape& over, const Shape& under);

    bool contains(posn) const override;
    color color_at(posn) const override;

private:
    const Shape& over_;
    const Shape& under_;
};
