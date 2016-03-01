#include "raster/color.h"

#include <UnitTest++/UnitTest++.h>

using namespace raster;

TEST(DefaultColor)
{
    color c;
    CHECK_EQUAL(0, c.value); // transparent
}

TEST(Black)
{
    CHECK_EQUAL(0xFF000000, color::black.value);
}

TEST(White)
{
    CHECK_EQUAL(0xFFFFFFFF, color::white.value);
}
