#include "Int_double_pair.h"
#include <UnitTest++/UnitTest++.h>

TEST(Construct)
{
    Int_double_pair p(4, 5.5);

    CHECK_EQUAL(4, p.first);
    CHECK_EQUAL(5.5, p.second);
}

TEST(Compare)
{
    Int_double_pair p1(4, 5.5);
    Int_double_pair p2(4, 5.7);
    Int_double_pair p3(5, 3);

    CHECK(!(p1 < p1));
    CHECK(p1 < p2);
    CHECK(p1 < p3);
    CHECK(!(p2 < p1));
    CHECK(!(p2 < p2));
    CHECK(p2 < p3);
    CHECK(!(p3 < p1));
    CHECK(!(p3 < p2));
    CHECK(!(p3 < p3));
}