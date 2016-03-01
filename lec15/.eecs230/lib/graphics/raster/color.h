#pragma once

#include <cstdint>

namespace raster
{

struct color
{
    uint32_t value;

    using byte = unsigned char;

    static constexpr byte BYTE_MAX = 255;

    color(byte red, byte green, byte blue, byte alpha = BYTE_MAX) noexcept;
    // color(const fcolor&) noexcept;

    // constructs transparent by default
    color() noexcept;

    explicit color(uint32_t argb) noexcept;

    static color const transparent;
    static color const white;
    static color const black;

    byte red()   const noexcept;
    byte green() const noexcept;
    byte blue()  const noexcept;
    byte alpha() const noexcept;
};

} // end namespace raster
