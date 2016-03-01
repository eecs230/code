#include "Polygon.h"

namespace geometry
{

Polygon::Polygon(std::initializer_list <Point> vertices)
        : vertices_{vertices}
{ }

const std::vector<Point>& Polygon::get_vertices() const
{
    return vertices_;
}

bool Polygon::contains(Point p)
{

}

} // end namespace geometry
