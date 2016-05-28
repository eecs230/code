#pragma once

#include "Drawing.h"

class Difference : public Drawing
{
public:
    Difference(drawing_ptr base, drawing_ptr mask);
    bool contains(posn) const override;
    color color_at(posn) const override;

private:
    drawing_ptr base_;
    drawing_ptr mask_;
};

drawing_ptr difference(drawing_ptr base, drawing_ptr mask);