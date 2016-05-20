#pragma once

#include <algorithm>

namespace graphics
{

// A floating-point sample in the range 0.0 to 1.0.
class sample
{
public:
    // Constructs a sample, clipping the given value into the correct
    // range.
    constexpr sample(double) noexcept;

    // Constructs the 0.0 sample
    constexpr sample() noexcept : sample{0.0} {}

    // The double value of a sample.
    double value() const noexcept { return value_; }
    explicit operator double() const noexcept { return value_; }

    sample operator*(sample other) const noexcept;
    sample& operator*=(sample) noexcept;

private:
    double value_;
    // INVARIANT: 0.0 ≤ value_ ≤ 1.0
};

sample interpolate(sample a, sample weight, sample b) noexcept;

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

namespace
{

constexpr double saturate(double value) noexcept
{
    if (value < 0.0) return 0.0;
    if (value > 1.0) return 1.0;
    return value;
}

}

constexpr sample::sample(double value) noexcept
        : value_{saturate(value)}
{}

} // namespace graphics
