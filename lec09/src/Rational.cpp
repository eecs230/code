#include "Rational.h"

static long gcd(long a, long b)
{
    while (a != 0) {
        long c = a;
        a = b % a;
        b = c;
    }

    return b;
}

Rational::Rational()
    : num_{0}, den_{1}
{ }

Rational::Rational(long n)
    : num_{n}, den_{1}
{ }

Rational::Rational(long n, long d)
{
    if (d == 0)
        throw std::overflow_error{"Rational::Rational: divide by 0"};

    long divisor = gcd(n, d);

    n /= divisor;
    d /= divisor;

    if (d < 0) {
        n = -n;
        d = -d;
    }

    num_ = n;
    den_ = d;
}

Rational Rational::reciprocal() const
{
    return Rational{den_, num_};
}

bool operator==(const Rational& a, const Rational& b)
{
    return a.get_numerator() == b.get_numerator()
        && a.get_denominator() == b.get_denominator();
}

bool operator!=(const Rational& a, const Rational& b)
{
    return !(a == b);
}

bool operator<(const Rational& a, const Rational& b)
{
    return a.get_numerator() * b.get_denominator() <
           b.get_numerator() * a.get_denominator();
}

bool operator>(const Rational& a, const Rational& b)
{
    return b < a;
}

bool operator<=(const Rational& a, const Rational& b)
{
    return !(b < a);
}

bool operator>=(const Rational& a, const Rational& b)
{
    return !(a < b);
}

std::ostream& operator<<(std::ostream& o, const Rational& a)
{
    return o << a.get_numerator() << "/" << a.get_denominator();
}

Rational operator-(const Rational& a)
{
    return Rational{-a.get_numerator(), a.get_denominator()};
}

Rational operator+(const Rational& a, const Rational& b)
{
    /*
    return Rational{a.get_numerator() * b.get_denominator() +
                    b.get_numerator() * a.get_denominator(),
                    a.get_denominator() * b.get_denominator()};
    */

    long divisor = gcd(a.get_denominator(), b.get_denominator());
    long a_den = a.get_denominator() / divisor;
    long b_den = b.get_denominator() / divisor;

    long a_num = a.get_numerator() * b_den;
    long b_num = b.get_numerator() * a_den;

    long numerator   = a_num + b_num;
    long denominator = a_den * b.get_denominator();

    return Rational{numerator, denominator};
}

Rational operator-(const Rational& a, const Rational& b)
{
    return a + -b;
}

Rational operator*(const Rational& a, const Rational& b)
{
    long ab_divisor = gcd(a.get_numerator(), b.get_denominator());
    long ba_divisor = gcd(b.get_numerator(), a.get_denominator());

    long a_num = a.get_numerator() / ab_divisor;
    long b_num = b.get_numerator() / ba_divisor;
    long a_den = a.get_denominator() / ba_divisor;
    long b_den = b.get_denominator() / ab_divisor;

    long num = a_num * b_num;
    long den = a_den * b_den;

    return Rational{num, den};
}

Rational operator/(const Rational& a, const Rational& b)
{
    return a * b.reciprocal();
}


Rational& operator+=(Rational& a, const Rational& b)
{
    return a = a + b;
}

Rational& operator-=(Rational& a, const Rational& b)
{
    return a = a - b;
}

Rational& operator*=(Rational& a, const Rational& b)
{
    return a = a * b;
}

Rational& operator/=(Rational& a, const Rational& b)
{
    return a = a / b;
}

Rational& operator++(Rational& a)
{
    return a += 1;
}

Rational operator++(Rational& a, int)
{
    Rational result = a;
    ++a;
    return result;
}

Rational& operator--(Rational& a)
{
    return a -= 1;
}

Rational operator--(Rational& a, int)
{
    Rational result = a;
    --a;
    return result;
}
