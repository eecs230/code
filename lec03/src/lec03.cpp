#include <eecs230.h>

// Squares a number.
int square(int x)
{
    return x * x;
}

// Computes the hypotenuse of a right triangle given the other
// two sides.
//
// Examples:
//
//   hypotenuse(3, 4)  ==  5
//   hypotenuse(3, -4) ==  5
//   hypotenuse(12, 5) ==  13
//
double hypotenuse(double a, double b) {
    return sqrt(square(a) + square(b));
}

int main() {
    vector<double> fs;
    double f;

    while (cin >> f) {
        if (f == 0) break;
        fs.push_back(f);
    }

    for (int i = 0; i < fs.size(); ++i)
        cout << fs[i] << '\n';

}
