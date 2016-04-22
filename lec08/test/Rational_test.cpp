#include "Rational.h"
#include <UnitTest++/UnitTest++.h>
#include <sstream>
#include <iostream>

using R = Rational;

TEST(DefaultConstructor)
{
    R r;
    CHECK_EQUAL(0, r.get_numerator());
    CHECK_EQUAL(1, r.get_denominator());
}

TEST(LongConstructor)
{
    R r = 8945;
    CHECK_EQUAL(8945, r.get_numerator());
    CHECK_EQUAL(1, r.get_denominator());

    r = -50;
    CHECK_EQUAL(-50, r.get_numerator());
    CHECK_EQUAL(1, r.get_denominator());
}

TEST(FractionConstructor)
{
    R r{4, 6};
    CHECK_EQUAL(2, r.get_numerator());
    CHECK_EQUAL(3, r.get_denominator());

    r = {-4, 6};
    CHECK_EQUAL(-2, r.get_numerator());
    CHECK_EQUAL(3, r.get_denominator());

    r = {4, -6};
    CHECK_EQUAL(-2, r.get_numerator());
    CHECK_EQUAL(3, r.get_denominator());

    r = {-4, -6};
    CHECK_EQUAL(2, r.get_numerator());
    CHECK_EQUAL(3, r.get_denominator());
}

TEST(AsDouble)
{
    R r{2, 3};
    CHECK_CLOSE(.66667, r.as_double(), 0.0001);
}

TEST(Equals)
{
    CHECK_EQUAL(true, R(2, 3) == R(2, 3));
    CHECK_EQUAL(true, R(4, 6) == R(2, 3));
    CHECK_EQUAL(false, R(5, 6) == R(2, 3));
}

TEST(NotEquals)
{
    CHECK_EQUAL(false, R(2, 3) != R(2, 3));
    CHECK_EQUAL(false, R(4, 6) != R(2, 3));
    CHECK_EQUAL(true, R(5, 6) != R(2, 3));
}

TEST(Comparisons)
{
    R a{2, 3};
    R b{3, 2};

    CHECK_EQUAL(false, a < a);
    CHECK_EQUAL(true,  a < b);
    CHECK_EQUAL(false, b < a);
    CHECK_EQUAL(false, b < b);

    CHECK_EQUAL(false, a > a);
    CHECK_EQUAL(false, a > b);
    CHECK_EQUAL(true,  b > a);
    CHECK_EQUAL(false, b > b);

    CHECK_EQUAL(true,  a <= a);
    CHECK_EQUAL(true,  a <= b);
    CHECK_EQUAL(false, b <= a);
    CHECK_EQUAL(true,  b <= b);

    CHECK_EQUAL(true,  a >= a);
    CHECK_EQUAL(false, a >= b);
    CHECK_EQUAL(true,  b >= a);
    CHECK_EQUAL(true,  b >= b);
}

TEST(Reciprocal)
{
    CHECK_EQUAL(R(2, 3), R(3, 2).reciprocal());
    CHECK_EQUAL(R(3, 2), R(2, 3).reciprocal());
    CHECK_EQUAL(R(-3, 2), R(-2, 3).reciprocal());
}

TEST(StreamInsertion)
{
    std::ostringstream os;

    os << Rational{2, 3} << ' ' << Rational{-5, 3} << ' ' << Rational{8};
    CHECK_EQUAL("2/3 -5/3 8/1", os.str());
}

TEST(Negation)
{
    CHECK_EQUAL(R(-2, 3), -R(2, 3));
    CHECK_EQUAL(R(LONG_MAX), -R(LONG_MIN + 1));
}

TEST(Addition)
{
    CHECK_EQUAL(R(5, 6), R(1, 3) + R(1, 2));
}

TEST(Subtraction)
{
    CHECK_EQUAL(R(-1, 6), R(1, 3) - R(1, 2));
}

TEST(Multiplication)
{
    CHECK_EQUAL(R(4, 27), R(4, 45) * R(5, 3));
}

TEST(Division)
{
    CHECK_EQUAL(R(4, 75), R(4, 45) / R(5, 3));
}
