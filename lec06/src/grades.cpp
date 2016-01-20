#include "eecs230.h"

// Sums the elements of a vector.
//
// Example:
//
//   sum({}) == 0
//
//   sum({ 1, 2, 3, 4 }) == 10
//
// Strategy: structural iteration
double sum(vector<double> grades)
{
    double result = 0.0;

    for (double grade : grades) result += grade;

    return result;
}

// Computes the average of a vector of grades.
//
// Example:
//
//   average_grade({}) throws runtime_error
//
//   average_grade({80, 90}) == 95
//
// Strategy: function composition
double average_grade(vector<double> grades)
{
    if (grades.empty()) error("No grades entered");

    return sum(grades) / grades.size();
}

// Reads a vector of doubles from stdin, stopping when it reads `sentinel`
//
// Example:
//
//   If call is read_doubles_until(0) and user inputs "3 4\n5 0 8\n", result
//   is vector<double>{3, 4, 5}
//
// Strategy: generative iteration
vector<double> read_doubles_until(double sentinel)
{
    vector<double> result;

    for (;;) {
        double d;
        if (! (cin >> d)) error("IO error");

        if (d == -1) break;

        result.push_back(d);
    }

    return result;
}

// Reads grades from the user and prints the average
int main()
try
{
    cout << "Please enter grades (-1 to stop):\n> ";
    vector<double> grades = read_doubles_until(-1);
    cout << "Average grade is " << average_grade(grades) << "\n";
}

catch (runtime_error& e) {
    cerr << "Caught in main: " << e.what() << endl;
    exit(1);
}

