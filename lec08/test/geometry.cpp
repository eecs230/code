#include "eecs230.h"
#include "geometry.h"

using namespace lec08;

TEST(Posn, Fields)
{
    Posn p{3, 4};

    EXPECT_EQ(3, p.x);
    EXPECT_EQ(4, p.y);
}

TEST(Posn, Distance)
{
    EXPECT_EQ(13, distance(Posn{3, 9}, Posn{8, 21}));
}

TEST(Circle, PosnWithin)
{
    Circle c{{3, 5}, 2};

    EXPECT_TRUE(is_within(Posn{3, 5}, c));
    EXPECT_TRUE(is_within(Posn{3, 6}, c));
    EXPECT_TRUE(is_within(Posn{4, 6}, c));
    EXPECT_FALSE(is_within(Posn{3, 7}, c));
    EXPECT_FALSE(is_within(Posn{4, 7}, c));
}

TEST(Circle, Within)
{
    Posn p{0, 0};
    Posn q{1, 0};

    EXPECT_TRUE(is_within(Circle{p, .5}, Circle{p, 1}));
    EXPECT_FALSE(is_within(Circle{p, 5}, Circle{p, 1}));
    EXPECT_TRUE(is_within(Circle{p, 1}, Circle{q, 3}));
    EXPECT_FALSE(is_within(Circle{p, 3}, Circle{q, 3}));
}

TEST(Circle, Tangent)
{
    Posn p{0, 0};
    Posn q{1, 0};

    EXPECT_TRUE(are_tangent(Circle{p, 0.5}, Circle{q, 0.5}));
    EXPECT_TRUE(are_tangent(Circle{p, 0.75}, Circle{q, 0.25}));
    EXPECT_FALSE(are_tangent(Circle{p, 0.85}, Circle{q, 0.25}));
    EXPECT_FALSE(are_tangent(Circle{p, 0.65}, Circle{q, 0.25}));
}
