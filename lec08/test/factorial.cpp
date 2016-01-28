// test/factorial.cpp

#include "factorial.h"
#include "eecs230.h"

TEST(Factorial, Zero)
{
    EXPECT_EQ(1, factorial(0));
}

TEST(Factorial, One)
{
    EXPECT_EQ(1, factorial(1));
}

TEST(Factorial, TwoThroughFive)
{
    EXPECT_EQ(2, factorial(2));
    EXPECT_EQ(6, factorial(3));
    EXPECT_EQ(24, factorial(4));
    EXPECT_EQ(120, factorial(5));
}
