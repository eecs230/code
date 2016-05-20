#pragma once

#include "Drawing_decorator.h"

// Adapts a shape to alter its opacity/transparency.
class Opacity : public Drawing_decorator
{
public:
    Opacity(drawing_ptr, graphics::sample);
    color color_at(posn) const override;

private:
    graphics::sample opacity_;
};

drawing_ptr opacity(drawing_ptr, graphics::sample);