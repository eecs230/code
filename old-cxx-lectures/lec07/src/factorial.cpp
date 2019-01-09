// src/factorial.cpp

#include "factorial.h"
#include "eecs230.h"

// Strategy: generative iteration
int factorial(int n)
{
    if (n < 0) throw runtime_error("factorial: negative");

    int result = 1;
    for (int i = 1; i <= n; ++i) result *= i;
    return result;
}
