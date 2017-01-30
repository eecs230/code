#include "factorial.h"
#include <eecs230.h>

int main()
{
    cout << "Enter a number:\n> ";

    long n;
    cin >> n;
    if (!cin) throw runtime_error("couldn't read a number");

    cout << n << "! == " << factorial(n) << '\n';
}