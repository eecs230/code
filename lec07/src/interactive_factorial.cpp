#include <eecs230.h>
#include "factorial.h"

int main()
{
    cout << "Enter a number:\n>";

    int n;
    cin >> n;
    if (!cin) throw runtime_error("didn't enter a number");

    cout << n << "! = " << factorial(n) << '\n';
}
