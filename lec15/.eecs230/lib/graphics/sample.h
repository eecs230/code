#pragma once

namespace graphics
{

// A floating-point sample in the range 0.0 to 1.0.
class sample
{
public:
    static sample const ZERO;
    static sample const ONE;

    // Constructs a sample, clipping the given value into the correct
    // range.
    explicit sample(double) noexcept;

    // Constructs the 0.0 sample
    sample() noexcept : sample{0.0} {}

    // The double value of a sample.
    double value() const noexcept { return value_; }
    operator double() const noexcept { return value_; }

    sample operator*(sample other) const noexcept;
    sample& operator*=(sample) noexcept;

private:
    double value_;
    // INVARIANT: 0.0 ≤ value_ ≤ 1.0
};

sample interpolate(sample a, double weight, sample b) noexcept;

inline bool operator==(sample a, sample b) noexcept
{ return a.value() == b.value(); }

inline bool operator!=(sample a, sample b) noexcept
{ return a.value() != b.value(); }

inline bool operator<(sample a, sample b) noexcept
{ return a.value() < b.value(); }

inline bool operator<=(sample a, sample b) noexcept
{ return a.value() <= b.value(); }

inline bool operator>(sample a, sample b) noexcept
{ return a.value() > b.value(); }

inline bool operator>=(sample a, sample b) noexcept
{ return a.value() >= b.value(); }

sample operator+(sample, sample) noexcept;
sample& operator+=(sample&, sample) noexcept;

sample operator-(sample, sample) noexcept;
sample& operator-=(sample&, sample) noexcept;

sample operator/(sample, sample) noexcept;
sample& operator/=(sample&, sample) noexcept;

} // namespace graphics
