#include "Polygon.h"

using posn = Polygon::posn;

Polygon::Polygon(std::initializer_list<posn> vertices)
        : Shape{vertices}, vertices_{vertices}
{ }

const std::vector<posn>& Polygon::get_vertices() const
{
    return vertices_;
}

bool has_crossing(posn previous, posn p, posn current)
{
    if (current.y < previous.y)
        std::swap(current, previous);

    if (previous.y <= p.y && p.y < current.y) {
        double y = p.y - previous.y;
        double x = p.x - previous.x;

        double dy = current.y - previous.y;
        double dx = current.x - previous.x;

        return y * dx > dy * x;
    } else {
        return false;
    }
}

bool Polygon::contains(posn p) const
{
    if (vertices_.size() == 0) return false;

    size_t crossings = 0;

    posn previous = vertices_.back();

    for (posn current : vertices_) {
        if (has_crossing(previous, p, current))
            ++crossings;

        previous = current;
    }

    return crossings % 2 == 1;
}

