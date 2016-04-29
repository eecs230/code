#pragma once

namespace graphics
{

// A floating-point sample in the range 0.0 to 1.0.
class sample
{
public:
    using repr_t = double;

    static sample const zero;
    static sample const one;

    // Constructs a sample, clipping the given value into the correct
    // range.
    sample(repr_t);

    // Constructs the 0.0 sample
    sample() : sample{0.0} {}

    // The repr_t value of a sample.
    repr_t value() const { return value_; }
    explicit operator repr_t() const { return value_; }

    sample operator*(sample other) const;
    sample& operator*=(sample);

private:
    repr_t value_;
    // INVARIANT: 0.0 ≤ value_ ≤ 1.0
};

sample interpolate(sample a, sample weight, sample b);

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
