#pragma once

#include "Shape.h"

class Background : public Shape
{
public:
    Background(color fill = color::white);
    bool contains(posn) const;
};