#pragma once

#include "Drawing.h"

class Intersection : public Drawing
{
public:
    Intersection(drawing_ptr base, drawing_ptr mask);
    bool contains(posn) const override;
    color color_at(posn) const override;

private:
    drawing_ptr base_;
    drawing_ptr mask_;
};

drawing_ptr intersection(drawing_ptr base, drawing_ptr mask);