#pragma once

#include "Shape.h"

#include <vector>

class Polygon : public Shape
{
public:
    Polygon(std::initializer_list<Point> vertices);

    bool contains(Point p) const override;

protected:
    const std::vector<Point>& get_vertices() const;

private:
    std::vector<Point> vertices_;
};
