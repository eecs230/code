#include "Opacity.h"

Opacity::Opacity(drawing_ptr base, graphics::sample opacity)
        : Drawing_decorator{base}
        , opacity_{opacity}
{ }

Drawing::color Opacity::color_at(posn point) const
{
    auto base_color = Drawing_decorator::color_at(point);
    return color{base_color.red(),
                 base_color.green(),
                 base_color.blue(),
                 opacity_ * base_color.alpha()};
}

drawing_ptr opacity(drawing_ptr base, graphics::sample opacity)
{
    return std::make_shared<Opacity>(base, opacity);
}
