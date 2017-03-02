#include "Nothing.h"

Nothing::Nothing()
        : Drawing(bbox::nothing())
{ }

bool Nothing::contains(posn) const
{
    return false;
}

drawing_ptr nothing()
{
    return std::make_shared<Nothing>();
}
