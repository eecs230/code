#include "Rectangle.h"

bool Rectangle::contains(posn point) const
{
    return get_bbox().contains(point);
}
