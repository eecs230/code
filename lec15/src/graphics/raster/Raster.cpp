#include "Raster.h"
#include "bmp_header.h"

#include <cassert>
#include <fstream>

namespace raster
{

Raster::Raster(size_t width, size_t height)
    : Raster{width, height, color::black}
{ }

Raster::Raster(size_t width, size_t height, color fill)
    : width_{width}
    , height_{height}
    , pixels_(width * height, fill)
{ }

color& Raster::at(size_t x, size_t y)
{
    assert(in_bounds(x, y));
    return pixels_[width() * y + x];
}

const color& Raster::at(size_t x, size_t y) const
{
    assert(in_bounds(x, y));
    return pixels_[width() * y + x];
}

bool Raster::in_bounds(size_t x, size_t y) const noexcept
{
    return x < width() && y < height();
}

void Raster::write_ppm(const std::string& filename) const
{
    std::ofstream of{filename};
    of << "P6\n";       // magic number
    of << width() << ' ' << height() << " 255\n";

    for (const auto& pixel : pixels_) {
        of << pixel.red() << pixel.green() << pixel.blue();
    }
}

void Raster::write_bmp(const std::string& filename) const
{
    std::ofstream of{filename};
    bmp::info_t info{width(), height()};
    bmp::file_t file{width(), height()};

    of.write((char *)&file, sizeof(file));
    of.write((char *)&info, sizeof(info));

    for (size_t y = 0; y < height(); ++y) {
        auto row = operator[](y);
        for (size_t x = 0; x < width(); ++x) {
            auto pixel = row[x];
            of << pixel.blue() << pixel.green() << pixel.red();
        }

        for (size_t x = 0; x < bmp::row_padding(width()); ++x) {
            of << '\0';
        }
    }
}

Raster::const_row_ref::const_row_ref(const Raster& raster, size_t y)
    : raster_{raster}, y_{y}
{ }

Raster::row_ref::row_ref(Raster& raster, size_t y)
    : const_row_ref{raster, y}
{ }

Raster::const_row_ref Raster::operator[](size_t y) const {
    assert(y < height());
    return Raster::const_row_ref{*this, y};
}

Raster::row_ref Raster::operator[](size_t y) {
    assert(y < height());
    return Raster::row_ref{*this, y};
}

const color& Raster::const_row_ref::operator[](size_t x) const
{
    return raster_.at(x, y_);
}

color& Raster::row_ref::operator[](size_t x)
{
    return const_cast<Raster&>(raster_).at(x, y_);
}

} // namespace raster
