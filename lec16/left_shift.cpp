// Shifting by the size of the value (or more) is undefined behavior. The
// reason to do this is that different CPUs have different semantics for
// their shift operations, and this ensures that C(++) implementations on
// different CPUs can all use the native shift instruction instead of having
// to do something slower. I get different results in release and debug modes.

#include <iostream>

int fun(int, int);

int main()
{
    int int_bits = sizeof(int) * 8;
    int start = 7;
    int finish = start << int_bits;

    std::cout << start << " << " << int_bits << " == " << finish << '\n';

    std::cout << fun(int_bits, start) << '\n';
}

int fun(int x, int y)
{
    if (y << x == y)
        return x;
    else return -1;
}

