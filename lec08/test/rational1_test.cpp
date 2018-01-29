#include "Rational1.h"
#include <eecs230.h>

using rational::Rational;
using rational::make_rational;

TEST(Rational_0)
{
    Rational r = make_rational();
    CHECK_EQUAL(0, r.num);
    CHECK_EQUAL(1, r.den);
}

TEST(Rational_n)
{
    Rational r = make_rational(5);
    CHECK_EQUAL(5, r.num);
    CHECK_EQUAL(1, r.den);
}

TEST(Rational_n_m)
{
    Rational r1 = make_rational(2, 3);
    CHECK_EQUAL(2, r1.num);
    CHECK_EQUAL(3, r1.den);

    Rational r2 = make_rational(4, 6);
    CHECK_EQUAL(2, r2.num);
    CHECK_EQUAL(3, r2.den);

    Rational r3 = make_rational(4, -6);
    CHECK_EQUAL(-2, r3.num);
    CHECK_EQUAL(3, r3.den);

    Rational r4 = make_rational(-4, -6);
    CHECK_EQUAL(2, r4.num);
    CHECK_EQUAL(3, r4.den);
}

TEST(Make_rational_x_0_throws)
{
    CHECK_THROW(make_rational(1, 0), overflow_error);
}

TEST(Rational_equals)
{
    Rational r1 = make_rational(2, 3);
    Rational r2 = make_rational(4, 6);
    CHECK_EQUAL(r1, r2);
}

TEST(Rational_comparisons)
{
    Rational r1 = make_rational(3, 10);
    Rational r2 = make_rational(4, 10);

    CHECK(r1 < r2);
    CHECK(r1 <= r2);
    CHECK(r2 > r1);
    CHECK(r2 >= r1);
    CHECK(!(r1 > r2));
    CHECK(!(r1 >= r2));
    CHECK(!(r2 < r1));
    CHECK(!(r2 <= r1));
    CHECK(r1 <= r1);
    CHECK(r2 <= r2);
    CHECK(r1 >= r1);
    CHECK(r2 >= r2);
}

TEST(Format)
{
    Rational r1 = make_rational(5);
    Rational r2 = make_rational(5, 6);
    ostringstream fmt;
    fmt << r1 << ' ' << r2;
    CHECK_EQUAL("5 5/6", fmt.str());
}

TEST(To_double)
{
    Rational r1 = make_rational(5);
    Rational r2 = make_rational(1, 3);

    CHECK_EQUAL(5, to_double(r1));
    CHECK_CLOSE(0.3333, to_double(r2), 0.0001);
}

TEST(Negate)
{
    Rational r1 = make_rational(5);
    Rational r2 = make_rational(1, 3);

    CHECK_EQUAL(make_rational(-5), -r1);
    CHECK_EQUAL(make_rational(-1, 3), -r2);
}

TEST(Reciprocal)
{
    Rational r1 = make_rational(5);
    Rational r2 = make_rational(1, 3);

    CHECK_EQUAL(make_rational(1, 5), reciprocal(r1));
    CHECK_EQUAL(make_rational(3), reciprocal(r2));
}

TEST(Reciprocal_0_throws)
{
    Rational r{0, 1};
    CHECK_THROW(reciprocal(r), overflow_error);
}

TEST(Rational_addition)
{
    CHECK_EQUAL(make_rational(11), make_rational(5) + make_rational(6));
    CHECK_EQUAL(make_rational(2,3), make_rational(1,3) + make_rational(1,3));
    CHECK_EQUAL(make_rational(7,12), make_rational(1,3) + make_rational(1,4));
    CHECK_EQUAL(make_rational(1), make_rational(5,12) + make_rational(7,12));
    CHECK_EQUAL(make_rational(35,12), make_rational(2,3) + make_rational(9,4));
    CHECK_EQUAL(make_rational(3,8), make_rational(1,8) + make_rational(1,4));
}

TEST(Rational_multiplication)
{
    CHECK_EQUAL(make_rational(12), make_rational(3) * make_rational(4));
    CHECK_EQUAL(make_rational(1), make_rational(1,3) * make_rational(3));
    CHECK_EQUAL(make_rational(1), make_rational(2,3) * make_rational(3,2));
}

