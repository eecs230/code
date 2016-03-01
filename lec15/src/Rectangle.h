#pragma once

#include "Polygon.h"

class Rectangle : public Polygon
{
public:
    Rectangle(double top, double right, double bottom, double left)
        : Polygon{{left, top}, {right, top}, {right, bottom}, {left, bottom}}
    { }

    Rectangle(posn p, posn q)
        : Polygon{{p.x, p.y}, {p.x, q.y}, {q.x, q.y}, {q.x, p.y}}
    { }

    bool contains(posn) const override;
};

