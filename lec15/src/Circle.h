#pragma once

#include "Shape.h"

class Circle : public Shape
{
public:
    Circle(posn center, double radius);
    bool contains(posn) const override;

private:
    posn center_;
    double radius_;
};