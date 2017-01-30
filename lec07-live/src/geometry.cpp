#include "geometry.h"

namespace geometry {

bool operator==(const Posn& p1, const Posn& p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator==(const Circle& c1, const Circle& c2)
{
    return c1.center == c2.center && c1.radius == c2.radius;
}

ostream& operator<<(ostream& o, const Posn& p)
{
    o << '(' << p.x << ", " << p.y << ')';
    return o;
}

ostream& operator<<(ostream& o, const Circle& c)
{
    o << "Circle { center = " << c.center << ", radius = "
      << c.radius << " }";
    return o;
}

double area(const Circle& c)
{
    return c.radius * c.radius * M_PI;
}

void double_radius(Circle& c)
{
    c.radius *= 2;
}

Circle double_radius_fun(const Circle& c)
{
    return Circle{c.center, 2 * c.radius};
}

double distance(const Posn& p1, const Posn& p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

bool is_within(const Posn& p, const Circle& c)
{
    return distance(p, c.center) < c.radius;
}

// Is circle `inner` within circle `outer`?
bool is_within(const Circle& inner, const Circle& outer)
{
    return distance(inner.center, outer.center) < outer.radius - inner.radius;
}

// Are the two circles tangent to one another?
bool are_tangent(const Circle& c1, const Circle& c2)
{
    return distance(c1.center, c2.center) == c1.radius + c2.radius;
}

}
