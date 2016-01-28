#include "geometry.h"
#include "eecs230.h"

using namespace lec08;

TEST(Posn, X)
{
    Posn p;
    p.x = 4;
    EXPECT_EQ(4, p.x);
}

TEST(Posn, Initialize)
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
    Circle c{Posn{3, 5}, 2};

    EXPECT_TRUE(is_within(Posn{3, 5}, c));
    EXPECT_TRUE(is_within(Posn{3, 6}, c));
    EXPECT_TRUE(is_within(Posn{4, 6}, c));
    EXPECT_FALSE(is_within(Posn{3, 7}, c));
    EXPECT_FALSE(is_within(Posn{4, 7}, c));
}







