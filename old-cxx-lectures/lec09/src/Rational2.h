#pragma once

#include <eecs230.h>

namespace rational {

// Represents a rational number, that is, a fraction.
class Rational
{
public:
    // Constructs the rational representing 0
    Rational();

    // Constructs the rational representing `n`
    Rational(long n);

    // Constructs the rational representing `n/d`; throws
    // overflow_error if `d` is 0.
    Rational(long n, long d);

    // Note: Only three arithmetic operations are members, and the rest
    // are free functions declared below. The reason is that these three
    // operations access the representation directly, but the other
    // arithmetic operations work via getters and constructors.

    // Negation -r
    Rational operator-() const;

    // Reciprocal 1/r
    Rational reciprocal() const;

    // Multiplication.
    Rational operator*(Rational) const;

    // Gets the numerator
    long numerator() const { return num_; }

    // Gets the denominator
    long denominator() const { return den_; }

private:
    long num_, den_;
    // invariants:
    //   den > 0
    //   gcd(num, den) == 1
};

bool operator==(Rational, Rational);
bool operator!=(Rational, Rational);
bool operator<(Rational, Rational);
bool operator<=(Rational, Rational);
bool operator>(Rational, Rational);
bool operator>=(Rational, Rational);

ostream& operator<<(ostream&, Rational);
double to_double(Rational);

Rational operator+(Rational, Rational);
Rational operator-(Rational, Rational);
Rational operator/(Rational, Rational);

Rational& operator+=(Rational&, Rational);
Rational& operator-=(Rational&, Rational);
Rational& operator*=(Rational&, Rational);
Rational& operator/=(Rational&, Rational);

// Pre-increment and pre-decrement:
Rational& operator++(Rational&);
Rational& operator--(Rational&);

// Post-increment and post-decrement:
Rational operator++(Rational&, int);
Rational operator--(Rational&, int);

}

// This enables writing rational numbers as literals with the suffix "_r".
// For example:
//
//  - 3_r
//  - 3/5_r
//
rational::Rational operator"" _r(unsigned long long);
