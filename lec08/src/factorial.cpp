#include "eecs230.h"
#include "factorial.h"

// Strategy: generative iteration
int factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; ++i) result *= i;
    return result;
}
