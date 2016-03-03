#pragma once

#include "Shape.h"

// A limitless expanse of color with infinite bounding box, suitable for use
// as a background for other shapes.
class Background : public Shape
{
public:
    // Constructs a background of the given color, white by default.
    Background(color fill = color::white);

    bool contains(posn) const;
};