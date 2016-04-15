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

int old_main()
{
    cout << "Enter a number:\n>";

    int n;
    if (!(cin >> n)) throw runtime_error("didn't enter a number");

    cout << n << "! = " << factorial(n) << '\n';
}
