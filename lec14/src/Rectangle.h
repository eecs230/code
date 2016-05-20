#pragma once

#include "Polygon.h"

// A rectangle with sides orthogonal to the axes. This is a special case of
// polygon that we can handle especially efficiently.
class Rectangle : public Polygon
{
public:
    // Constructs a rectangle with the given top, right, bottom, and left
    // coordinates.
    Rectangle(double top, double right, double bottom, double left)
        : Polygon{{left, top}, {right, top}, {right, bottom}, {left, bottom}}
    { }

    // Constructs a rectangle with the given positions as opposing vertices.
    Rectangle(posn p, posn q)
        : Polygon{{p.x, p.y}, {p.x, q.y}, {q.x, q.y}, {q.x, p.y}}
    { }

    bool contains(posn) const override;
};

drawing_ptr rectangle(double top, double right, double bottom, double left);
