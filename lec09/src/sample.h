#pragma once

#include <iostream>

namespace graphics
{

// A floating-point sample in the range 0.0 to 1.0.
//
// This class ensures that the contained value is always in the range. It
// supports numeric operations while maintaining the invariant.
class sample
{
public:
    using repr_t = double;

    static sample const zero;
    static sample const one;

    // Constructs a sample, clipping the given value into the correct
    // range. (Note: because this is a constructor of one argument, it will
    // be applied implicitly to convert doubles to samples where necessary.)
    sample(repr_t);

    // Constructs the 0.0 sample
    sample() : value_(0.0) {}

    // The repr_t value of a sample.
    repr_t value() const { return value_; }

    // For coercions back to double (which must be explicit).
    explicit operator repr_t() const { return value_; }

    sample operator*(sample) const;
    sample& operator*=(sample);

private:
    repr_t value_;
    // INVARIANT: 0.0 ≤ value_ ≤ 1.0
};

sample interpolate(sample a, sample weight, sample b);

std::ostream& operator<<(std::ostream&, sample);
std::istream& operator>>(std::istream&, sample&);

inline bool operator==(sample a, sample b)
{ return a.value() == b.value(); }

inline bool operator!=(sample a, sample b)
{ return a.value() != b.value(); }

inline bool operator<(sample a, sample b)
{ return a.value() < b.value(); }

inline bool operator<=(sample a, sample b)
{ return a.value() <= b.value(); }

inline bool operator>(sample a, sample b)
{ return a.value() > b.value(); }

inline bool operator>=(sample a, sample b)
{ return a.value() >= b.value(); }

sample operator+(sample, sample);
sample& operator+=(sample&, sample);

sample operator-(sample, sample);
sample& operator-=(sample&, sample);

sample operator/(sample, sample);
sample& operator/=(sample&, sample);

} // namespace graphics
