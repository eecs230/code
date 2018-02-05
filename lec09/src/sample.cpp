#include "sample.h"

#include <algorithm>

namespace graphics
{

namespace
{

sample::repr_t saturate(sample::repr_t value)
{
    return std::min(1.0, std::max(0.0, value));
}

}

sample const sample::zero {0.0};
sample const sample::one  {1.0};

sample::sample(repr_t value)
    : value_{saturate(value)}
{}

std::ostream& operator<<(std::ostream& os, sample x)
{
    return os << x.value();
}

std::istream& operator>>(std::istream& is, sample& x)
{
    double temp;
    is >> temp;
    x = sample(temp);
    return is;
}

sample interpolate(sample a, sample weight, sample b)
{
    return sample{(1 - weight.value()) * a.value() + weight.value() * b.value()};
}

sample sample::operator*(sample other) const
{
    sample result;
    result.value_ = value() * other.value(); // can't overflow
    return result;
}

sample& sample::operator*=(sample other)
{
    value_ *= other.value(); // cannot overflow
    return *this;
}

sample operator+(sample a, sample b)
{
    return sample{a.value() + b.value()};
}

sample& operator+=(sample& target, sample other)
{
    return target = target + other;
}

sample operator-(sample a, sample b)
{
    return sample{a.value() - b.value()};
}

sample& operator-=(sample& target, sample other)
{
    return target = target - other;
}

sample operator/(sample a, sample b)
{
    return sample{a.value() / b.value()};
}

sample& operator/=(sample& target, sample other)
{
    return target = target / other;
}

} // namespace graphics
