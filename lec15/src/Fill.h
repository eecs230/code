#pragma once

#include "Shape.h"

#include <memory>

// Adapts another shape to change its color.
class Fill : public Shape
{
public:
    Fill(const Shape&, const color&);
    bool contains(posn) const override;

private:
    const Shape& base_;
};
