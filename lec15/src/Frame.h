#pragma once

#include "Shape.h"

class Frame : public Shape
{
public:
    Frame(color fill = color::white);
    bool contains(posn) const;
};