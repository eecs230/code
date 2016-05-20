#include "Drawing_decorator.h"

Drawing_decorator::Drawing_decorator(drawing_ptr base)
        : Drawing_decorator{base, {&*base}}
{ }

Drawing_decorator::Drawing_decorator(drawing_ptr base, bbox box)
        : Drawing{box}
        , base_{base}
{ }

bool Drawing_decorator::contains(posn point) const
{
    return base_->contains(point);
}

graphics::color Drawing_decorator::color_at(posn point) const
{
    return base_->color_at(point);
}
