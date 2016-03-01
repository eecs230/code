#include "Opacity.h"

Opacity::Opacity(const Shape& base, graphics::sample opacity)
        : Shape{bbox{base}}
        , base_{base}
        , opacity_{opacity}
{ }

bool Opacity::contains(posn point) const
{
    return base_.contains(point);
}

Shape::color Opacity::color_at(posn point) const
{
    auto base_color = base_.color_at(point);
    return color{base_color.red(),
                 base_color.green(),
                 base_color.blue(),
                 opacity_ * base_color.alpha()};
}