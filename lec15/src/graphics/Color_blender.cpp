#include "Color_blender.h"

namespace raster
{

Color_blender::Color_blender() noexcept
{ }

Color_blender& Color_blender::add(double weight, const F_color& color) noexcept
{
    double alpha = weight * color.alpha();

    red_    += alpha * color.red();
    green_  += alpha * color.green();
    blue_   += alpha * color.blue();
    alpha_  += alpha;
    weight_ += weight;

    return *this;
}

Color_blender& operator<<(Color_blender& cb, const F_color& color) noexcept
{
    cb.add(1, color);
    return cb;
}

Color_blender::operator F_color() const noexcept
{
    if (weight_ == 0)
        return F_color::transparent;
    else
        return F_color{red_ / alpha_, green_ / alpha_, blue_ / alpha_,
                       alpha_ / weight_};
}

} // end namespace raster
