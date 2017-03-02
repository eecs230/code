#include "Background.h"

Background::Background(color fill) : Drawing{bbox::everything(), fill}
{ }

bool Background::contains(posn) const
{
    return true;
}

drawing_ptr background(Drawing::color fill)
{
    return std::make_shared<Background>(fill);
}
