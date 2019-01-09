#include "Rational2.h"

using rational::Rational;

TEST(Rational_0)
{
    Rational r;
    CHECK_EQUAL(0, r.numerator());
    CHECK_EQUAL(1, r.denominator());
}

TEST(Rational_n)
{
    Rational r(5);
    CHECK_EQUAL(5, r.numerator());
    CHECK_EQUAL(1, r.denominator());
}

TEST(Rational_n_m)
{
    Rational r1(2, 3);
    CHECK_EQUAL(2, r1.numerator());
    CHECK_EQUAL(3, r1.denominator());

    Rational r2(4, 6);
    CHECK_EQUAL(2, r2.numerator());
    CHECK_EQUAL(3, r2.denominator());

    Rational r3(4, -6);
    CHECK_EQUAL(-2, r3.numerator());
    CHECK_EQUAL(3, r3.denominator());

    Rational r4(-4, -6);
    CHECK_EQUAL(2, r4.numerator());
    CHECK_EQUAL(3, r4.denominator());
}

TEST(Rational_den0_throws) {
    CHECK_THROW(Rational(5, 0), overflow_error);
}

TEST(Rational_equals)
{
    Rational r1(2, 3);
    Rational r2(4, 6);
    CHECK_EQUAL(r1, r2);
}

TEST(Rational_comparisons)
{
    Rational r1(3, 10);
    Rational r2(4, 10);

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
    Rational r1(5);
    Rational r2(5, 6);
    ostringstream fmt;
    fmt << r1 << ' ' << r2;
    CHECK_EQUAL("5 5/6", fmt.str());
}

TEST(To_double)
{
    Rational r1(5);
    Rational r2(1, 3);

    CHECK_EQUAL(5, to_double(r1));
    CHECK_CLOSE(0.3333, to_double(r2), 0.0001);
}

TEST(Negate)
{
    Rational r1(5);
    Rational r2(1, 3);

    CHECK_EQUAL(Rational(-5), -r1);
    CHECK_EQUAL(Rational(-1, 3), -r2);
}

TEST(Reciprocal)
{
    Rational r1(5);
    Rational r2(1, 3);

    CHECK_EQUAL(Rational(1, 5), r1.reciprocal());
    CHECK_EQUAL(Rational(3), r2.reciprocal());
}

TEST(Reciprocal_0_throws)
{
    Rational r(0);
    CHECK_THROW(r.reciprocal(), overflow_error);
}

TEST(Rational_addition)
{
    using R = Rational;

    CHECK_EQUAL(11_r, 5_r + 6_r);
    CHECK_EQUAL(2/3_r, 1/3_r + 1/3_r);
    CHECK_EQUAL(7/12_r, 1/3_r + 1/4_r);
    CHECK_EQUAL(1_r, 5/12_r + 7/12_r);
    CHECK_EQUAL(35/12_r, 2/3_r + 9/4_r);
    CHECK_EQUAL(3/8_r, 1/8_r + 1/4_r);
}

TEST(Rational_multiplication)
{
    using R = Rational;

    CHECK_EQUAL(R(12), R(3) * R(4));
    CHECK_EQUAL(R(1), R(1,3) * R(3));
    CHECK_EQUAL(R(1), R(2,3) * R(3,2));
}

