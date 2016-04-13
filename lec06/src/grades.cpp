#include <eecs230.h>

// Strategies you have available:
//
// generative iteration: a loop that produces something of arbitrary
// size (like a vector)
//
// structural iteration: a loop that traverses a data structure, e.g. a
// for-each loop over a vector
//
// function composition: solving a problem by combining other functions

//
// WISHLIST:
//

// Reads a vector of grades from cin, stopping with -1.
//
// Examples:
//
// If the user enters "5 6 8 -1\n", result is {5, 6, 8}
// If the user enters "5 6\n8 -1\n", result is {5, 6, 8}
// If the user enters "-1\n", result is {}
//
// Strategy: generative iteration
vector<double> read_grades()
{
    vector<double> result;
    double grade = 0;

    while (cin >> grade && grade != -1)
        result.push_back(grade);

    return result;
}

// Sums a vector of doubles.
//
// Examples:
//
//   sum({}) == 0
//   sum({1, 2, 3, 4}) == 10
//
// Strategy: structural iteration
double sum(vector<double> doubles)
{
    double result = 0;

    for (double d : doubles)
        result += d;

    return result;
}

// Averages a vector of grades.
//
// Examples:
//
//   average_grades({}) throw runtime_error
//   average_grades({80, 90}) == 85
//
// Strategy: function composition
double average_grades(vector<double> grades)
{
    if (grades.size() == 0) error("No grades to average");
    return sum(grades) / grades.size();
}

// END WISHLIST

// Reads grades from the user and prints the average
int main()
try
{
    cout << "Please enter grades (-1 to stop)\n> ";
    vector<double> grades = read_grades();
    cout << "Average grade is " << average_grades(grades) << "\n";
}

catch (runtime_error& e) {
    cerr << "Caught in main: " << e.what() << endl;
    exit(1);
}

