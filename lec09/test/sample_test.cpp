#include "sample.h"

#include <UnitTest++/UnitTest++.h>

using namespace graphics;

using S = sample;

TEST(Sample_0)
{
    CHECK_EQUAL(0,   S().value());
}

TEST(Sample_N)
{
    CHECK_EQUAL(.5,  S(.5).value());
    CHECK_EQUAL(1,   S(1.5).value());
    CHECK_EQUAL(0,   S(-.5).value());
}

TEST(Sample_times)
{
    CHECK_EQUAL(S(.25),  S(.5) * S(.5));
    CHECK_EQUAL(S(0),    S(0) * S(.5));
    CHECK_EQUAL(S(.4),   S(.4) * S(1));
    CHECK_EQUAL(S(.125), S(.5) * S(.25));
}

TEST(Sample_plus)
{
    CHECK_EQUAL(S(1),    S(.5) + S(.5));
    CHECK_EQUAL(S(.75),  S(.5) + S(.25));
    CHECK_EQUAL(S(1),    S(.5) + S(.75));
}
