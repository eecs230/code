#include "Fill.h"

Fill::Fill(drawing_ptr base, const color& color)
        : Drawing(base->get_bbox())
        , base_{base}
        , color_{color}
{ }

bool Fill::contains(posn point) const
{
    return base_->contains(point);
}

color Fill::color_at(posn point) const
{
    if (base_->contains(point))
        return color_;
    else
        return color::transparent;
}

drawing_ptr fill(drawing_ptr base, const Drawing::color& color)
{
    return std::make_shared<Fill>(base, color);
}
