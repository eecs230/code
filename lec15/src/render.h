#pragma once

#include "graphics.h"
#include "Shape.h"

void simple_render(const Shape&, graphics::raster&);

void render(const Shape&, graphics::raster&, size_t antialias = 3);

