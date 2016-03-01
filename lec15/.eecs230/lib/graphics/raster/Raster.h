#pragma once

#include "color32.h"

#include <string>
#include <vector>

namespace graphics
{

class raster
{
public:
    raster(size_t width, size_t height);
    raster(size_t width, size_t height, color32 fill);

    // forward declaration
    class const_row_ref;
    class row_ref;

    color32      & at(size_t x, size_t y);
    const color32& at(size_t x, size_t y) const;

    const_row_ref operator[](size_t) const;
    row_ref operator[](size_t);

    size_t width() const noexcept { return width_; }
    size_t height() const noexcept { return height_; }

    bool in_bounds(size_t x, size_t y) const noexcept;

    void write_ppm(const std::string& filename) const;
    void write_bmp(const std::string& filename) const;

    class const_row_ref
    {
    public:
        const color32& operator[](size_t) const;

    private:
        friend class raster;
        const_row_ref(const raster&, size_t y);

        const raster& raster_;
        const size_t y_;
    };

    class row_ref : const_row_ref
    {
    public:
        color32& operator[](size_t);

    private:
        friend class raster;
        row_ref(raster&, size_t y);
    };

private:
    size_t               width_, height_;
    std::vector<color32> pixels_;
};

} // namespace raster
