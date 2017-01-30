#include "Transform.h"

// To transform a shape, we
//  1) transform the bounding box, and
//  2) apply the *inverse transformation* to positions before passing them to
//     the shape.

Transform::Transform(drawing_ptr base, const graphics::affinity& transform)
        : Drawing_decorator{base, transform(bbox{&*base})}
        , inv_{transform.inverse()}
{ }

bool Transform::contains(posn point) const {
    return Drawing_decorator::contains(inv_(point));
}

Drawing::color Transform::color_at(posn point) const {
    return Drawing_decorator::color_at(inv_(point));
}

drawing_ptr transform(drawing_ptr base, const graphics::affinity& transform)
{
    return std::make_shared<Transform>(base, transform);
}
