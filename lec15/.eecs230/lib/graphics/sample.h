#pragma once

#include <algorithm>

namespace graphics
{

class sample;

// A floating-point sample in the range 0.0 to 1.0.
class sample
{
public:
    using repr = double;

    // Constructs a sample, clipping the given value into the correct
    // range.
    constexpr sample(repr) noexcept;

    // Constructs the 0.0 sample
    constexpr sample() noexcept : value_{0.0} {}

    static const sample zero;
    static const sample one;

    // The repr value of a sample.
    constexpr repr value() const noexcept { return value_; }
    explicit constexpr operator repr() const noexcept { return value_; }

    constexpr sample operator*(sample other) const noexcept;
    constexpr sample& operator*=(sample) noexcept;

    constexpr sample operator+(sample other) const noexcept;
    constexpr sample& operator+=(sample other) noexcept;

    constexpr sample operator-(sample other) const noexcept;
    constexpr sample& operator-=(sample other) noexcept;

    constexpr sample operator/(sample other) const noexcept;
    constexpr sample& operator/=(sample other) noexcept;

    constexpr sample invert() const noexcept;

    constexpr sample interpolate(sample weight, sample other) const noexcept;

private:
    repr value_;
    // INVARIANT: 0.0 ≤ value_ ≤ 1.0

    static constexpr sample from_unchecked(repr);
};

constexpr sample interpolate(sample a, sample weight, sample b) noexcept;

constexpr bool operator==(sample a, sample b) noexcept;
constexpr bool operator!=(sample a, sample b) noexcept;
constexpr bool operator<(sample a, sample b) noexcept;
constexpr bool operator<=(sample a, sample b) noexcept;
constexpr bool operator>(sample a, sample b) noexcept;
constexpr bool operator>=(sample a, sample b) noexcept;

///
/// IMPLEMENTATION STARTS HERE
///

namespace
{

constexpr sample::repr saturate(sample::repr value) noexcept
{
    if (value < 0.0) return 0.0;
    if (value > 1.0) return 1.0;
    return value;
}

}

constexpr sample::sample(sample::repr value) noexcept
        : value_{saturate(value)}
{}

constexpr sample sample::invert() const noexcept
{
    return from_unchecked(1 - value_);
}

constexpr sample interpolate(sample a, sample weight, sample b) noexcept
{
    return a.interpolate(weight, b);
}

constexpr sample sample::operator*(sample other) const noexcept
{
    return from_unchecked(value_ * other.value_); // cannot overflow
}

constexpr sample& sample::operator*=(sample other) noexcept
{
    value_ *= other.value(); // cannot overflow
    return *this;
}

constexpr sample sample::operator+(sample other) const noexcept
{
    sample result(*this);
    result += other;
    return result;
}

constexpr sample& sample::operator+=(sample other) noexcept
{
    value_ += other.value(); // can't go negative
    if (value_ > 1.0) value_ = 1.0;
    return *this;
}

constexpr sample sample::operator-(sample other) const noexcept
{
    sample result(*this);
    result -= other;
    return result;
}

constexpr sample& sample::operator-=(sample other) noexcept
{
    value_ -= other.value(); // can go negative but not over 1
    if (value_ < 0.0) value_ = 0.0;
    return *this;
}

constexpr sample sample::operator/(sample other) const noexcept
{
    sample result(*this);
    result /= other;
    return result;
}

constexpr sample& sample::operator/=(sample other) noexcept
{
    if (value_ < other.value())
        value_ /= other.value();
    else
        value_ = 1.0;
    return *this;
}

constexpr sample sample::interpolate(sample weight, sample other) const noexcept
{
    return from_unchecked((1 - weight.value()) * value_ +
                                  weight.value() * other.value());
}

constexpr sample sample::from_unchecked(repr value)
{
    sample result;
    result.value_ = value;
    return result;
}

constexpr bool operator==(sample a, sample b) noexcept
{ return a.value() == b.value(); }

constexpr bool operator!=(sample a, sample b) noexcept
{ return a.value() != b.value(); }

constexpr bool operator<(sample a, sample b) noexcept
{ return a.value() < b.value(); }

constexpr bool operator<=(sample a, sample b) noexcept
{ return a.value() <= b.value(); }

constexpr bool operator>(sample a, sample b) noexcept
{ return a.value() > b.value(); }

constexpr bool operator>=(sample a, sample b) noexcept
{ return a.value() >= b.value(); }
} // namespace graphics
