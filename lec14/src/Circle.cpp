#include "circle.h"

// Computes the bounding box of a circle, given its center and radius.
static Drawing::bbox bbox_of_circle(Drawing::posn center, double radius)
{
        return Drawing::bbox(center.y - radius, center.x + radius,
                             center.y + radius, center.x - radius);
}

Circle::Circle(posn center, double radius)
        : Drawing{bbox_of_circle(center, radius)}
        , center_{center}
        , radius_{radius}
{ }

bool Circle::contains(posn point) const
{
    return distance(center_, point) <= radius_;
}

drawing_ptr circle(Drawing::posn center, double radius)
{
    return std::make_shared<Circle>(center, radius);
}
