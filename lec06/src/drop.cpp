#include <eecs230.h>

/*
 * Reads weights and grades from the user; computes the final grade by
 * dropping the grade the maximizes the weighted average.
 */

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

    for (double d : doubles) result += d;

    return result;
}

// Computes the dot product of two vectors, multiplying them pointwise and
// summing.
//
// Example:
//   sum_of_products({1, 10, 100}, {7, 3, 4}) = 437
//
// Strategy: structure iteration
double sum_of_products(vector<double> xs, vector<double> ys)
{
    double result = 0;

    for (int i = 0; i < xs.size(); ++i)
        result += xs[i] * ys[i];

    return result;
}

// Breaks a line into a vector of doubles.
//
// Example:
//
//   If line is "3 4.5 8", result {3, 4.5, 8}
//
// Strategy: generative iteration
vector<double> split_string(string line)
{
    istringstream  ss{line};
    vector<double> result;
    double         d;

    while (ss >> d) result.push_back(d);

    return result;
}

// Reads a vector of doubles from one line of cin.
//
// Example:
//
//   If user input is "3 4.5 8\n12\n", result {3, 4.5, 8}
//
// Strategy: function composition
vector<double> read_double_vector()
{
    string line;
    getline(cin, line);
    return split_string(line);
}

// Ensures that grades and weights have the same length, and they're
// non-empty.
//
// Examples:
//
//   given {2, 3, 4} {.3, .3, .4}, returns successfully
//   given {2, 3, 4} {.3, .3}, throws runtime_error
//   given {} {}, throws runtime_error
//
// Strategy: decision tree
void check_input(vector<double> grades, vector<double> weights)
{
    if (grades.size() != weights.size())
        error("Grades and weights must be same length");

    if (grades.size() < 2)
        error("Must have at least 2 grades");
}

// Computes the weighted average, omitting `dropped`
//
// Example:
//
//   compute_grade_without(2, { .5, .7, 1 }, { 1, 1, 4 }) = 0.6
//
// Strategy: function composition
double compute_grade_without(int dropped,
                             vector<double> grades,
                             vector<double> weights)
{
    double numerator   = sum_of_products(grades, weights);
    double denominator = sum(weights);

    numerator   -= grades[dropped] * weights[dropped];
    denominator -= weights[dropped];

    return numerator / denominator;
}

// Finds the index of the grade whose omission maximizes the weighted
// average.
//
// Examples:
//
//   { 90, 90, 10 }, { .4, .3, .3 } => 2
//   { 20, 80, 90 }, { 0.01, 0.89, 0.1 } => 1
//
// Strategy: structural iteration via counting
int find_best_drop(vector<double> grades, vector<double> weights)
{
    int best_index = -1;
    double best_average = 0.0;

    for (int i = 0; i < grades.size(); ++i) {
        double average = compute_grade_without(i, grades, weights);
        if (average > best_average) {
            best_index   = i;
            best_average = average;
        }
    }

    if (best_index == -1) error("find_best_drop: no best grade found");

    return best_index;
}

int main()
try
{
    cout << "Please enter the grades on one line:\n> ";
    vector<double> grades = read_double_vector();

    cout << "Please enter the weights on one line:\n> ";
    vector<double> weights = read_double_vector();

    check_input(grades, weights);

    int to_drop  = find_best_drop(grades, weights);
    double grade = compute_grade_without(to_drop, grades, weights);

    cout << "Grade: " << grade << ", maximized by dropping assignment "
         << to_drop << '\n';
}

catch (runtime_error& e) {
    cerr << "Caught in main: " << e.what() << endl;
    exit(1);
}
