#pragma once

#include <graphics.h>

#include <memory>

// Abstract base class for renderable shapes.
class Shape
{
public:
    using color = graphics::color;
    using posn  = graphics::posn<double>;
    using bbox  = graphics::bbox<double>;

    // Constructs a shape with the given bounding box and color.
    Shape(const bbox&, const color& = color::black);

    // Gets the bounding box of the shape.
    const bbox& get_bbox() const;

    // Returns whether the given position lies within the shape. Derived
    // classes must override this to specify their form.
    virtual bool contains(posn) const = 0;

    // Returns the color of the shape at the given position. By default, it
    // returns color_ for positions contained within the shape, and
    // transparent otherwise.
    virtual color color_at(posn) const;

    // Classes with virtual functions need a virtual destructor.
    virtual ~Shape();

private:
    bbox  bbox_;
    color color_;
};
