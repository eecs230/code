#pragma once

#include "graphics.h"
#include "Shape.h"

void render(const Shape&, raster::Raster&, size_t antialias = 3);

