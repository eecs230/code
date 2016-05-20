#include "sample.h"

#include <algorithm>

namespace graphics
{

sample interpolate(sample a, sample weight, sample b) noexcept
{
    return sample{(1 - weight.value()) * a.value() + weight.value() * b.value()};
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
