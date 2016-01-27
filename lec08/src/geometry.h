#pragma once

namespace geometry {

// Represents the point (x, y)
struct Posn
{
    double x, y;
};

// Computes the distance between two points
double distance(const Posn&, const Posn&);

// Represents a circle with the given center and radius
struct Circle
{
    Posn   center;
    double radius;
};

// Is the given position within the given circle?
bool is_within(const Posn&, const Circle&);

// Is circle `inner` within circle `outer`?
bool is_within(const Circle& inner, const Circle& outer);

// Are the two circles tangent to one another?
bool are_tangent(const Circle&, const Circle&);

// Represents a rectangle with its upper-left vertex at the given position,
// and the given dimensions
struct Rectangle
{
    Posn   upper_left;
    double width, height;
};

} // end namespace geometry
