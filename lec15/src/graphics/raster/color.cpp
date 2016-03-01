#include "color.h"

#include <algorithm>

namespace raster
{

using byte = color::byte;
auto constexpr BYTE_MAX = color::BYTE_MAX;

static size_t constexpr
    RED_SHIFT   = 16,
    GREEN_SHIFT = 8,
    BLUE_SHIFT  = 0,
    ALPHA_SHIFT = 24;

color::color(byte red, byte green, byte blue, byte alpha) noexcept
    : value{static_cast<uint32_t>((red   << RED_SHIFT)
                                | (green << GREEN_SHIFT)
                                | (blue  << BLUE_SHIFT)
                                | (alpha << ALPHA_SHIFT))}
{
    if (alpha == 0) value = 0;
}

color::color(uint32_t argb) noexcept : value{argb}
{}

color::color() noexcept : color{0, 0, 0, 0} {}

color const color::transparent{0, 0, 0, 0};
color const color::white{BYTE_MAX, BYTE_MAX, BYTE_MAX};
color const color::black{0, 0, 0};

byte color::red()   const noexcept
{
    return static_cast<byte>((value >> RED_SHIFT) & 0xFF);
}

byte color::green() const noexcept
{
    return static_cast<byte>((value >> GREEN_SHIFT) & 0xFF);
}

byte color::blue()  const noexcept
{
    return static_cast<byte>((value >> BLUE_SHIFT) & 0xFF);
}

byte color::alpha() const noexcept
{
    return static_cast<byte>((value >> ALPHA_SHIFT) & 0xFF);
}

} // namespace raster
