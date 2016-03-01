#pragma once

#include "Shape.h"

class Overlay : public Shape
{
public:
    Overlay(const Shape& over, const Shape& under);
    bool contains(posn) const override;
    color color_at(posn) const override;

private:
    const Shape& over_;
    const Shape& under_;
};
