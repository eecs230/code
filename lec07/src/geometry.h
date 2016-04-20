// src/geometry.h

#pragma once

#include <eecs230.h>

namespace lec07 {

// Represent the point (x, y)
struct Posn
{
    double x;
    double y;
};

// Represents the circle with center and radius
struct Circle
{
    Posn center;
    double radius;
};

// Computes the distance between two points.
double distance(const Posn&, const Posn&);

// Is the given point within the given circle?
bool is_within(const Posn&, const Circle&);

// Is circle `inner` within circle `outer`?
bool is_within(const Circle& inner, const Circle& outer);

// Are the two circles tangent to one another?
bool are_tangent(const Circle&, const Circle&);

} // end namespace lec07
