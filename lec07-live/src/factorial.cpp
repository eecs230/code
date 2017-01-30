#include <eecs230.h>

long factorial(long n)
{
    if (n < 0) throw runtime_error("factorial given negative number");

    long result = 1;
    for (long i = 1; i <= n; ++i) result *= i;
    return result;
}