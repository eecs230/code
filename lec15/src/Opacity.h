#pragma once

#include "Shape.h"

class Opacity : public Shape
{
public:
    Opacity(const Shape&, graphics::sample);
    Opacity(const Shape&, double);

    bool contains(posn) const override;
    color color_at(posn) const override;

private:
    const Shape& base_;
    graphics::sample opacity_;
};