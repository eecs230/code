#pragma once

#include <iostream>

// Rational numbers (fractions) as ratios of longs
class Rational
{
public:
    // Constructs 0
    Rational();
    // Constructs the rational representation of a long
    Rational(long);
    // Constructs the fraction numerator/denominator
    Rational(long numerator, long denominator);

    long get_numerator() const
    { return num_; }

    long get_denominator() const
    { return den_; }

    double as_double() const
    { return num_ / double(den_); }

    Rational reciprocal() const;

private:
    long num_;
    long den_;
    // INVARIANTS:
    //  - den_ > 0
    //  - gcd(num_, den_) == 1
};

bool operator==(const Rational&, const Rational&);
bool operator!=(const Rational&, const Rational&);
bool operator<(const Rational&, const Rational&);
bool operator>(const Rational&, const Rational&);
bool operator<=(const Rational&, const Rational&);
bool operator>=(const Rational&, const Rational&);

std::ostream& operator<<(std::ostream&, const Rational&);

Rational operator-(const Rational&);

Rational operator+(const Rational&, const Rational&);
Rational operator-(const Rational&, const Rational&);
Rational operator*(const Rational&, const Rational&);
Rational operator/(const Rational&, const Rational&);

Rational& operator+=(Rational&, const Rational&);
Rational& operator-=(Rational&, const Rational&);
Rational& operator*=(Rational&, const Rational&);
Rational& operator/=(Rational&, const Rational&);

// Preincrement operators ++r and --r
Rational& operator++(Rational&);
Rational& operator--(Rational&);

// Postincrement operators r++ and r--
Rational operator++(Rational&, int);
Rational operator--(Rational&, int);

