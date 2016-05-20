#include "Rectangle.h"

bool Rectangle::contains(posn point) const
{
    return get_bbox().contains(point);
}

drawing_ptr rectangle(double top, double right, double bottom, double left)
{
    return std::make_shared<Rectangle>(top, right, bottom, left);
}
