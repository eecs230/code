#include "Background.h"

Background::Background(color fill) : Shape{bbox::everything(), fill}
{ }

bool Background::contains(posn) const
{
    return true;
}

