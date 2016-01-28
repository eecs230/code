// src/geometry.cpp

#include "geometry.h"
#include "eecs230.h"

namespace lec08 {

double sqr(double x) { return x * x; }

// Strategy: domain knowledge
double distance(const Posn& p, const Posn& q)
{
    return sqrt(sqr(p.x - q.x) + sqr(p.y - q.y));
}

// Is the given point within the given circle?
// Strategy: domain knowledge
bool is_within(const Posn& p, const Circle& c)
{
    return distance(p, c.center) < c.radius;
}

// Is circle `inner` within circle `outer`?
// Strategy: domain knowledge
bool is_within(const Circle& inner, const Circle& outer)
{
    return distance(inner.center, outer.center) < outer.radius - inner.radius;
}

// Are the two circles tangent to one another?
// Strategy: domain knowledge
bool are_tangent(const Circle& c1, const Circle& c2)
{
    return distance(c1.center, c2.center) == c1.radius + c2.radius;
}

} // end namespace lec08
