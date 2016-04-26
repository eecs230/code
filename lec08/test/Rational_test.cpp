#include "Rational.h"
#include <UnitTest++/UnitTest++.h>

using R = Rational;

TEST(DefaultConstructor)
{
    R r;
    CHECK_EQUAL(0, r.get_numerator());
    CHECK_EQUAL(1, r.get_denominator());
}
