#pragma once

#include "Drawing.h"

#include <memory>

// Adapts another shape to change its color.
class Fill : public Drawing
{
public:
    Fill(drawing_ptr, const color&);
    bool contains(posn) const override;
    color color_at(posn) const override;

private:
    const drawing_ptr base_;
    const color color_;
};

drawing_ptr fill(drawing_ptr, const Drawing::color&);
