// test/factorial.cpp

#include "factorial.h"
#include "eecs230.h"

TEST(FactorialZero)
{
    CHECK_EQUAL(1, factorial(0));
}

TEST(FactorialOne)
{
    CHECK_EQUAL(1, factorial(1));
}

TEST(FactorialTwoThroughFive)
{
    CHECK_EQUAL(2, factorial(2));
    CHECK_EQUAL(6, factorial(3));
    CHECK_EQUAL(24, factorial(4));
    CHECK_EQUAL(120, factorial(5));
}
