#pragma once

#include "Drawing.h"

// Abstract class for shapes the adapt/decorate another shape. This stores
// the shape-to-be-decorated and passes through function calls to it by
// default. Derive and override to change the behavior.
class Drawing_decorator : public Drawing
{
public:
    // Decorates the given shape, using its bounding box as the decorator's
    // bounding box.
    Drawing_decorator(drawing_ptr);

    // Decorates the given shape, using the given bounding box.
    Drawing_decorator(drawing_ptr, bbox);

    bool contains(posn) const;
    color color_at(posn) const;

private:
    const drawing_ptr base_;
};
