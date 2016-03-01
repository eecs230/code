#include "Fill.h"

Fill::Fill(const Shape& base, const color& color)
        : Shape(base.get_bbox(), color)
        , base_{base}
{ }

bool Fill::contains(posn point) const
{
    return base_.contains(point);
}

