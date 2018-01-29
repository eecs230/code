#include "Rational1.h"

namespace rational {

namespace {

long gcd(long a, long b)
{
    while (a != 0) {
        long c = a;
        a = b % a;
        b = c;
    }

    return b;
}

}

Rational make_rational()
{
    return Rational{0, 1};
}

Rational make_rational(long value)
{
    return Rational{value, 1};
}

Rational make_rational(long n, long d)
{
    if (d == 0)
        throw std::overflow_error{"Rational::Rational: divide by 0"};

    long divisor = gcd(n, d);
    n /= divisor;
    d /= divisor;

    if (d < 0) {
        return Rational{-n, -d};
    } else {
        return Rational{n, d};
    }
}

bool operator==(Rational a, Rational b)
{
    return a.num == b.num && a.den == b.den;
}

bool operator!=(Rational a, Rational b)
{
    return !(a == b);
}

bool operator<(Rational a, Rational b)
{
    return a.num * b.den < b.num * a.den;
}

bool operator<=(Rational a, Rational b)
{
    return !(b < a);
}

bool operator>(Rational a, Rational b)
{
    return b < a;
}

bool operator>=(Rational a, Rational b)
{
    return b <= a;
}

std::ostream& operator<<(std::ostream& o, Rational r)
{
    if (r.den == 1)
        return o << r.num;
    else
        return o << r.num << '/' << r.den;
}

double to_double(Rational r)
{
    return r.num / (double) r.den;
}

Rational operator-(Rational r)
{
    return make_rational(-r.num, r.den);
}

Rational reciprocal(Rational r)
{
    return make_rational(r.den, r.num);
}

Rational operator+(Rational a, Rational b)
{
//    return make_rational(a.num * b.den + b.num * a.den,
//                         a.den * b.den);

    long divisor = gcd(a.den, b.den);
    long a_den = a.den / divisor;
    long b_den = b.den / divisor;

    long a_num = a.num * b_den;
    long b_num = b.num * a_den;

    long numerator   = a_num + b_num;
    long denominator = a_den * b_den * divisor;

    return make_rational(numerator, denominator);
}

Rational operator*(Rational a, Rational b)
{
//    return make_rational(a.num * b.num, a.den * b.den);

    long ab_divisor = gcd(a.num, b.den);
    long ba_divisor = gcd(b.num, a.den);

    long a_num = a.num / ab_divisor;
    long b_num = b.num / ba_divisor;
    long a_den = a.den / ba_divisor;
    long b_den = b.den / ab_divisor;

    long numerator   = a_num * b_num;
    long denominator = a_den * b_den;

    return Rational{numerator, denominator};
}

Rational operator-(Rational a, Rational b)
{
    return a + -b;
}

Rational operator/(Rational a, Rational b)
{
    return a * reciprocal(b);
}

Rational& operator+=(Rational& r, Rational other)
{
    return r = r + other;
}

Rational& operator-=(Rational& r, Rational other)
{
    return r = r - other;
}

Rational& operator*=(Rational& r, Rational other)
{
    return r = r * other;
}

Rational& operator/=(Rational& r, Rational other)
{
    return r = r / other;
}

Rational& operator++(Rational& r)
{
    return r += make_rational(1);
}

Rational& operator--(Rational& r)
{
    return r -= make_rational(1);
}

Rational operator++(Rational& r, int)
{
    Rational result = r;
    ++r;
    return result;
}

Rational operator--(Rational& r, int)
{
    Rational result = r;
    --r;
    return result;
}

}
