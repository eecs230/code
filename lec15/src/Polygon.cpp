#include "Polygon.h"

Polygon::Polygon(std::initializer_list<Point> vertices)
        : Shape{vertices}, vertices_{vertices}
{ }

const std::vector<Point>& Polygon::get_vertices() const
{
    return vertices_;
}

bool has_crossing(Point previous, Point p, Point current)
{
    if (current.y <= p.y && p.y < previous.y) {
        double y = p.y - current.y;
        double x = p.x - current.x;

        double dy = previous.y - current.y;
        double dx = previous.x - current.x;

        return y * dx > dy * x;
    }
    else if (previous.y <= p.y && p.y < current.y) {
        double y = p.y - previous.y;
        double x = p.x - previous.x;

        double dy = current.y - previous.y;
        double dx = current.x - previous.x;

        return y * dx > dy * x;
    } else {
        return false;
    }
}

bool Polygon::contains(Point p) const
{
    if (vertices_.size() == 0) return false;

    size_t crossings = 0;

    Point previous = vertices_.back();

    for (Point current : vertices_) {
        if (has_crossing(previous, p, current))
            ++crossings;

        previous = current;
    }

    return crossings % 2 == 1;
}

