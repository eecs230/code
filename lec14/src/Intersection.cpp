#include "Intersection.h"

Intersection::Intersection(drawing_ptr base, drawing_ptr mask)
        : Drawing{base->get_bbox() * mask->get_bbox()}
        , base_{base}
        , mask_{mask}
{ }

bool Intersection::contains(posn point) const
{
    return mask_->contains(point) && base_->contains(point);
}

Drawing::color Intersection::color_at(posn point) const
{
    if (mask_->contains(point))
        return base_->color_at(point);
    else
        return color::transparent;
}

drawing_ptr intersection(drawing_ptr base, drawing_ptr mask)
{
    return std::make_shared<Intersection>(base, mask);
}