#include "Transform.h"

// To transform a shape, we
//  1) transform the bounding box, and
//  2) apply the *inverse transformation* to positions before passing them to
//     the shape.

Transform::Transform(const Shape& base, const graphics::affinity& transform)
        : Shape_decorator{base, transform(bbox{&base})}
        , inv_{transform.inverse()}
{ }

bool Transform::contains(posn point) const {
    return Shape_decorator::contains(inv_(point));
}

Shape::color Transform::color_at(posn point) const {
    return Shape_decorator::color_at(inv_(point));
}
