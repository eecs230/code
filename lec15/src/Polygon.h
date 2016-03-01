#pragma once

#include "Shape.h"

namespace geometry
{

class Polygon : public Shape
{
public:
    Polygon(std::initializer_list<Point> vertices);

    bool contains(Point p);

protected:
    const std::vector<Point>& get_vertices() const;

private:
    std::vector<Point> vertices_;
};

} // end namespace geometry
