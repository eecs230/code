#include "Color.h"

#include <UnitTest++/UnitTest++.h>

using namespace graphics;

TEST(Color)
{
    Color c{1, .5, .25};

    CHECK_EQUAL(1, c.red());
    CHECK_EQUAL(.5, c.green());
    CHECK_EQUAL(.25, c.blue());
    CHECK_EQUAL(1, c.alpha());
}

TEST(Interpolate)
{
    Color red{1, 0, 0};
    Color green{0, 1, 0};
    Color orange{.5, .5, 0};

    CHECK_EQUAL(orange, interpolate(red, .5, green));
}
