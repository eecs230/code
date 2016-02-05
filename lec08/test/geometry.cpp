#include "geometry.h"
#include "eecs230.h"

using namespace lec08;

TEST(PosnX)
{
    Posn p;
    p.x = 4;
    CHECK_EQUAL(4, p.x);
}

TEST(PosnInitialize)
{
    Posn p{3, 4};
    CHECK_EQUAL(3, p.x);
    CHECK_EQUAL(4, p.y);
}

TEST(PosnDistance)
{
    CHECK_EQUAL(13, distance(Posn{3, 9}, Posn{8, 21}));
}

TEST(CirclePosnWithin)
{
    Circle c{Posn{3, 5}, 2};

    CHECK_EQUAL(true, is_within(Posn{3, 5}, c));
    CHECK_EQUAL(true, is_within(Posn{3, 6}, c));
    CHECK_EQUAL(true, is_within(Posn{4, 6}, c));
    CHECK_EQUAL(false, is_within(Posn{3, 7}, c));
    CHECK_EQUAL(false, is_within(Posn{4, 7}, c));
}







