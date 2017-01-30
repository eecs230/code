#pragma once

#include <eecs230.h>

namespace geometry {

// Represents the point (x, y)
struct Posn
{
    double x;
    double y;
};

// Represents the circle with given center and radius
struct Circle
{
    Posn center;
    double radius;
};

bool operator==(const Posn&, const Posn&);
bool operator==(const Circle&, const Circle&);

ostream& operator<<(ostream&, const Posn&);
ostream& operator<<(ostream&, const Circle&);

// Computes the area of a circle.
double area(const Circle&);

// Doubles the radius of a circle.
void double_radius(Circle&);

// Doubles the radius of a circle.
Circle double_radius_fun(const Circle&);

// Computes the distance between two points.
double distance(const Posn&, const Posn&);

// Is the given point within the given circle?
bool is_within(const Posn&, const Circle&);

// Is circle `inner` within circle `outer`?
bool is_within(const Circle& inner, const Circle& outer);

// Are the two circles tangent to one another?
bool are_tangent(const Circle&, const Circle&);

}
