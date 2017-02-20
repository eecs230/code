#include "Int_double_pair.h"

Int_double_pair::Int_double_pair(int i, double d)
        : first_(i), second_(d)
{ }

int Int_double_pair::first() const
{
    return first_;
}

double Int_double_pair::second() const
{
    return second_;
}

bool operator==(const Int_double_pair& a, const Int_double_pair& b)
{
    return a.first() == b.first() && a.second() == b.second();
}

bool operator!=(const Int_double_pair& a, const Int_double_pair& b)
{
    return !(a == b);
}

bool operator< (const Int_double_pair& a, const Int_double_pair& b)
{
    return a.first() < b.first() ||
            (a.first() == b.first() && a.second() < b.second());

}

bool operator<=(const Int_double_pair& a, const Int_double_pair& b)
{
    return !(b < a);
}

bool operator> (const Int_double_pair& a, const Int_double_pair& b)
{
   return b < a;
}

bool operator>=(const Int_double_pair& a, const Int_double_pair& b)
{
    return !(a < b);
}
