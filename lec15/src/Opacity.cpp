#include "Opacity.h"

Opacity::Opacity(const Shape& base, graphics::sample opacity)
        : Shape_decorator{base}
        , opacity_{opacity}
{ }

Shape::color Opacity::color_at(posn point) const
{
    auto base_color = Shape_decorator::color_at(point);
    return color{base_color.red(),
                 base_color.green(),
                 base_color.blue(),
                 opacity_ * base_color.alpha()};
}