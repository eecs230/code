#pragma once

#include "Drawing.h"

// The empty drawing
class Nothing : public Drawing
{
public:
    Nothing();
    bool contains(posn) const override;
};

drawing_ptr nothing();