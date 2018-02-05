#include "Rational2.h"

namespace rational {

namespace {

static long gcd(long a, long b)
{
    while (a != 0) {
        long c = a;
        a = b % a;
        b = c;
    }

    return b;
}

}

Rational::Rational() : num_(0), den_(1)
{ }

Rational::Rational(long n) : num_(n), den_(1)
{ }

Rational::Rational(long n, long d) {
    if (d == 0)
        throw overflow_error{"Rational::Rational: divide by 0"};

    long divisor = gcd(n, d);
    n /= divisor;
    d /= divisor;

    if (d < 0) {
        num_ = -n;
        den_ = -d;
    } else {
        num_ = n;
        den_ = d;
    }
}

Rational Rational::operator-() const
{
    Rational result;
    result.num_ = -num_;
    result.den_ = den_;
    return result;
}

Rational Rational::reciprocal() const
{
    if (num_ == 0) throw overflow_error("Rational: reciprocal of 0");

    Rational result;
    result.num_ = den_;
    result.den_ = num_;

    return result;
}

Rational Rational::operator*(Rational other) const
{
//    return Rational(num_ * other.num_, den_ * other.den_);

    long ab_divisor = gcd(num_, other.den_);
    long ba_divisor = gcd(other.num_, den_);

    long a_num = num_ / ab_divisor;
    long a_den = den_ / ba_divisor;
    long b_num = other.num_ / ba_divisor;
    long b_den = other.den_ / ab_divisor;

    Rational result;
    result.num_ = a_num * b_num;
    result.den_ = a_den * b_den;

    return result;
}

bool operator==(Rational a, Rational b)
{
    return a.numerator() == b.numerator() &&
            a.denominator() == b.denominator();
}

bool operator!=(Rational a, Rational b)
{
    return !(a == b);
}

bool operator<(Rational a, Rational b)
{
    return a.numerator() * b.denominator() < b.numerator() * a.denominator();
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

ostream& operator<<(ostream& o, Rational r)
{
    if (r.denominator() == 1)
        return o << r.numerator();
    else
        return o << r.numerator() << '/' << r.denominator();
}

double to_double(Rational r)
{
    return r.numerator() / (double) r.denominator();
}

Rational operator+(Rational a, Rational b)
{
//    return Rational(a.num * b.den + b.num * a.den,
//                    a.den * b.den);

    long divisor = gcd(a.denominator(), b.denominator());
    long a_den = a.denominator() / divisor;
    long b_den = b.denominator() / divisor;

    long a_num = a.numerator() * b_den;
    long b_num = b.numerator() * a_den;

    long numerator   = a_num + b_num;
    long denominator = a_den * b_den * divisor;

    return Rational(numerator, denominator);
}

Rational operator-(Rational a, Rational b)
{
    return a + -b;
}

Rational operator/(Rational a, Rational b)
{
    return a * b.reciprocal();
}

Rational& operator+=(Rational& a, Rational b)
{
    return a = a + b;
}

Rational& operator-=(Rational& a, Rational b)
{
    return a = a - b;
}

Rational& operator*=(Rational& a, Rational b)
{
    return a = a * b;
}

Rational& operator/=(Rational& a, Rational b)
{
    return a = a / b;
}

Rational& operator++(Rational& r)
{
    return r = r + Rational(1);
}

Rational& operator--(Rational& r)
{
    return r = r - Rational(1);
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

rational::Rational operator"" _r(unsigned long long n)
{
    return rational::Rational(static_cast<long>(n));
}

