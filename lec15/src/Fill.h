#pragma once

#include "Shape.h"

#include <memory>

class Fill : public Shape
{
public:
    Fill(const Shape&, const color&);
    bool contains(posn) const override;

private:
    const Shape& base_;
};
