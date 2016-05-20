#pragma once

#include "Drawing.h"
#include <initializer_list>

// Composes two shapes by overlaying one over the other.
class Overlay : public Drawing
{
public:
    // Places `over` over `under`.
    Overlay(drawing_ptr over, drawing_ptr under);

    bool contains(posn) const override;
    color color_at(posn) const override;

private:
    const drawing_ptr over_;
    const drawing_ptr under_;
};

drawing_ptr overlay(drawing_ptr over, drawing_ptr under);

drawing_ptr overlay(std::initializer_list<drawing_ptr>);
