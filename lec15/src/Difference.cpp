#include "Difference.h"

Difference::Difference(drawing_ptr base, drawing_ptr mask)
        : Drawing{base->get_bbox() * mask->get_bbox()}
        , base_{base}
        , mask_{mask}
{ }

bool Difference::contains(posn point) const
{
    return (!mask_->contains(point)) && base_->contains(point);
}

Drawing::color Difference::color_at(posn point) const
{
    if (! mask_->contains(point))
        return base_->color_at(point);
    else
        return color::transparent;
}

drawing_ptr difference(drawing_ptr base, drawing_ptr mask)
{
    return std::make_shared<Difference>(base, mask);
}