#include "Transform.h"

Transform::Transform(const Shape& base, const graphics::affinity& transform)
        : Shape{transform(bbox(base))}
        , base_{base}
        , inv_{transform.inverse()}
{ }

bool Transform::contains(posn point) const {
    return base_.contains(inv_(point));
}

Shape::color Transform::color_at(posn point) const {
    return base_.color_at(inv_(point));
}
