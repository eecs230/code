#include "circle.h"

static Shape::bbox bbox_of_circle(Shape::posn center, double radius)
{
        return Shape::bbox(center.y - radius, center.x + radius,
                           center.y + radius, center.x - radius);
}

Circle::Circle(posn center, double radius)
        : Shape{bbox_of_circle(center, radius)}
        , center_{center}
        , radius_{radius}
{ }

bool Circle::contains(posn point) const
{
    return distance(center_, point) <= radius_;
}
