#include "Background.h"

Background::Background(color fill) : Drawing{bbox::everything(), fill}
{ }

bool Background::contains(posn) const
{
    return true;
}

