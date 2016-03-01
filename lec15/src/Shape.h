#pragma once

#include "Point.h"

namespace geometry
{

class Shape
{
public:
    virtual bool contains(Point) const = 0;

    virtual ~Shape()
    { }
};

} // end namespace geometry
