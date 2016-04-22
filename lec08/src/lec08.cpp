#include "eecs230.h"

#include <iostream>
#include <sstream>

static long gcd(long a, long b)
{
    while (a != 0) {
        long c = a;
        a = b % a;
        b = c;
    }

    return b;
}

int main(int argc, const char* argv[])
{
    std::istringstream a{argv[1]};
    std::istringstream b{argv[2]};
    long c, d;
    a >> c;
    b >> d;
    std::cout << "gcd(" << c << ", " << d << ") == " << gcd(c, d) << "\n";
}
