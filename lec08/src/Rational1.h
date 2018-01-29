#pragma once

#include <iostream>
#include <stdexcept>

namespace rational {

// Represents a rational number, that is, a fraction.
struct Rational
{
    long num, den;
    // Invariants:
    //   gcd(num, den) == 1
    //   den > 0
};

Rational make_rational();
Rational make_rational(long value);
Rational make_rational(long num, long den);

bool operator==(Rational, Rational);
bool operator!=(Rational, Rational);
bool operator<(Rational, Rational);
bool operator<=(Rational, Rational);
bool operator>(Rational, Rational);
bool operator>=(Rational, Rational);

std::ostream& operator<<(std::ostream&, Rational);
double to_double(Rational);

Rational operator-(Rational);
Rational reciprocal(Rational);

Rational operator+(Rational, Rational);
Rational operator*(Rational, Rational);
Rational operator-(Rational, Rational);
Rational operator/(Rational, Rational);

Rational& operator+=(Rational&, Rational);
Rational& operator-=(Rational&, Rational);
Rational& operator*=(Rational&, Rational);
Rational& operator/=(Rational&, Rational);

Rational& operator++(Rational&);
Rational& operator--(Rational&);
Rational operator++(Rational&, int);
Rational operator--(Rational&, int);

}
