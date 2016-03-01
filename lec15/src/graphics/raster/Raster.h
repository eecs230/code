#pragma once

#include "color.h"

#include <string>
#include <vector>

namespace raster
{

class Raster
{
public:
    Raster(size_t width, size_t height);
    Raster(size_t width, size_t height, color fill);

    // forward declaration
    class const_row_ref;
    class row_ref;

    color& at(size_t x, size_t y);
    const color& at(size_t x, size_t y) const;

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
        const color& operator[](size_t) const;

    private:
        friend class Raster;
        const_row_ref(const Raster&, size_t y);

        const Raster& raster_;
        const size_t y_;
    };

    class row_ref : const_row_ref
    {
    public:
        color& operator[](size_t);

    private:
        friend class Raster;
        row_ref(Raster&, size_t y);
    };

private:
    size_t width_, height_;
    std::vector<color> pixels_;
};

} // namespace raster
