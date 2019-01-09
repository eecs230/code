//
// Reads the lengths of two sides of a right triangle from the user, and
// prints the length of the hypotenuse.
//

#include <eecs230.h>

// Computes the square of n.
//
// Example: square(3) == 9
double square(double n)
{
    return n * n;
}

// Computes the hypotenuse of a right triangle.
//
// Examples:
//   hypotenuse(3, 4)  == 5
//   hypotenuse(5, 12) == 13
double hypotenuse(double n1, double n2)
{
    return sqrt(square(n1) + square(n2));
}

int main() {
    cout << "Please enter the lengths of the two sides\n> ";

    double side1, side2;
    cin >> side1 >> side2;
    if (! cin) {
        simple_error("Could not read numbers.");
    }

    cout << "The hypotenuse has length " << hypotenuse(side1, side2) << "\n";
}
