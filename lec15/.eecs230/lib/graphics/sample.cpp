#include "sample.h"

#include <algorithm>

namespace graphics
{

namespace
{

double saturate(double value) noexcept
{
    return std::min(1.0, std::max(0.0, value));
}

}

sample const sample::ZERO {0.0};
sample const sample::ONE  {1.0};

sample::sample(double value) noexcept
    : value_{saturate(value)}
{}

sample interpolate(sample a, double weight, sample b) noexcept
{
    return sample{(1 - weight) * a + weight * b};
}

sample sample::operator*(sample other) const noexcept
{
    sample result;
    result.value_ = value() * other.value(); // can't overflow
    return result;
}

sample& sample::operator*=(sample other) noexcept
{
    value_ *= other.value(); // cannot overflow
    return *this;
}

sample operator+(sample a, sample b) noexcept {
    return sample{a.value() + b.value()};
}

sample& operator+=(sample& target, sample other) noexcept {
    return target = target + other;
}

sample operator-(sample a, sample b) noexcept {
    return sample{a.value() - b.value()};
}

sample& operator-=(sample& target, sample other) noexcept {
    return target = target - other;
}

sample operator/(sample a, sample b) noexcept {
    return sample{a.value() / b.value()};
}

sample& operator/=(sample& target, sample other) noexcept {
    return target = target / other;
}

} // namespace graphics
