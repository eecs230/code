#include "eecs230.h"

int main() {
    double a, b;

    cin >> a >> b;
    if (!cin) simple_error("Could not read input.");

    cout << sqrt(a * a + b * b) << '\n';
}
