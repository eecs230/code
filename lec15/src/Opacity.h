#pragma once

#include "Shape_decorator.h"

class Opacity : public Shape_decorator
{
public:
    Opacity(const Shape&, graphics::sample);
    color color_at(posn) const override;

private:
    graphics::sample opacity_;
};