#pragma once

#include <graphics.h>

#include <memory>

// Abstract base class for renderable drawings.
class Drawing
{
public:
    using color = graphics::color;
    using posn  = graphics::posn<double>;
    using bbox  = graphics::bbox<double>;

    // Constructs a drawing with the given bounding box.
    Drawing(const bbox&);

    // Gets the bounding box of the drawing.
    const bbox& get_bbox() const;

    // Returns whether the given position lies within the drawing. Derived
    // classes must override this to specify their form.
    virtual bool contains(posn) const = 0;

    // Returns the color of the drawing at the given position. By default, it
    // returns color_ for positions contained within the drawing, and
    // transparent otherwise.
    virtual color color_at(posn) const;

    // Classes with virtual functions need a virtual destructor.
    virtual ~Drawing();

private:
    bbox  bbox_;
};

using drawing_ptr = std::shared_ptr<Drawing>;
