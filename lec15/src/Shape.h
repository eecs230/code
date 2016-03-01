#pragma once

#include <graphics.h>

#include <memory>

class Shape
{
public:
    using color = graphics::color;
    using posn  = graphics::posn<double>;
    using bbox  = graphics::bbox<double>;

    Shape(const bbox&, const color& = color::black);

    const bbox& get_bbox() const;

    virtual bool contains(posn) const = 0;
    virtual color color_at(posn) const;

    virtual ~Shape();

private:
    bbox  bbox_;
    color color_;
};
