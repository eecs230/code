#include "eecs230.h"

// Sums the elements of a vector.
//
// Examples:
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

// Sums the pairwise products of two equal-length vectors (like dot
// product)
//
// Examples:
//
//   sum_of_products({1, 2, 3}, {1, 20, 300}) == 941
//
//   sum_of_products({}, {}) == 0
//
//   sum_of_products({5}, {}) throws runtime_error
//
// Strategy: structural iteration, via counting
double sum_of_products(vector<double> v, vector<double> u)
{
    if (v.size() != u.size()) error("sum_of_products: different vector lengths");

    double result = 0.0;

    for (int i = 0; i < v.size(); ++i)
        result += v[i] * u[i];

    return result;
}

// Computes the average of a vector of grades.
//
// Examples:
//
//   compute_average({}) throws runtime_error
//
//   compute_average({80, 90}, {.4, .6}) == 84
//
// Strategy: function composition
double compute_average(vector<double> grades, vector<double> weights)
{
    if (sum(weights) == 0) error("compute_average: sum(weights) is 0");
    return sum_of_products(grades, weights) / sum(weights);
}

// Computes the sum of a vector with index `ix` omitted.
//
// Example:
//
//   sum_without(2, {1, 20, 300, 4000}) == 4021
//
// Strategy: function composition
double sum_without(int ix, vector<double> v)
{
    return sum(v) - v[ix];
}

// Sums the pairwise products of two equal-length vectors (like dot
// product), with index `ix` omitted.
//
// Examples:
//
//   sum_of_products_without(1, {1, 2, 3}, {1, 20, 300}) == 901
//
// Strategy: function composition
double sum_of_products_without(int ix, vector<double> v, vector<double> u)
{
    return sum_of_products(v, u) - v[ix] * u[ix];
}

// Computes the average grade with assignment `ix` omitted from both
// the numerator and the denominator
//
// Examples:
//
//   compute_grade_without(2, {80, 80, 20, 70}, {1, 1, 1, 1}) == 76.66667
double
compute_grade_without(int n, vector<double> grades, vector<double> weights)
{
    double den = sum_without(n, weights);
    double num = sum_of_products_without(n, grades, weights);

    if (den == 0) return 0; // why?

    return num / den;
}

// Finds the assignment index whose dropping maximizes the remaining grade.
//
//   Examples:
//
//     find_best_drop({100, 100, 100, 99, 100}, {.2, .2, .2, .2, 2}) == 3
//
//     find_best_drop({20, 80, 90}, {0.01, 0.89, 0.1}) == 1
//
// Strategy: structural iteration, via counting
int find_best_drop(vector<double> grades, vector<double> weights)
{
    int    best_index = -1;
    double best_grade = 0.0;

    for (int i = 0; i < grades.size(); ++i) {
        double grade = compute_grade_without(i, grades, weights);
        if (grade > best_grade) best_index = i;
    }

    if (best_index == -1) error("find_best_drop: no best grade found");

    return best_index;
}

// Splits a string at spaces into a vector of doubles.
//
// Examples:
//
//   split_into_doubles("3 4.5 6") == {3., 4.5, 6.}
//
//   split_into_doubles("  ") == {}
//
// Strategy: generative iteration
vector<double> split_into_doubles(string line)
{
    vector<double> result;

    istringstream ss{line};
    double        d;
    while (ss >> d) result.push_back(d);

    return result;
}

// Reads one line of input and breaks it into a vector of doubles.
//
//   Example:
//
//     If user input is "3 3.5 6", result is {3., 3.5, 6.}
//
// Strategy: function composition
vector<double> read_double_vector()
{
    string buf;

    getline(cin, buf);
    if (!cin) error("read_double_vector: I/O error");

    return split_into_doubles(buf);
}

// Checks the input grades and weights for validity. They are invalid
// if they are different lengths or if the sum of the weights isn't
// a positive number.
//
// Examples:
//
//   check_input({3, 4, 5}, {.3, .3, .4}) returns successfully
//
//   check_input({3, 4, 5}, {.3, .7}) throws runtime_error
//
//   check_input({}, {}) throws runtime_error
//
// Strategy: decision tree
void check_input(vector<double> grades, vector<double> weights)
{
    if (grades.size() != weights.size()) {
        cerr << "Must enter same number of grades and weights\n";
        exit(1);
    }

    if (sum(weights) <= 0) {
        cerr << "Sum of weights must be positive\n";
        exit(1);
    }
}

// Reads grades and weights and finds which grade to drop to maximize
// the average grade.
//
// Strategy: function composition
int main()
try
{
    cout << "Please enter grades on one line:\n> ";
    vector<double> grades = read_double_vector();

    cout << "Please enter weights on one line:\n> ";
    vector<double> weights = read_double_vector();

    check_input(grades, weights);

    int    to_drop = find_best_drop(grades, weights);
    double grade   = compute_grade_without(to_drop, grades, weights);

    cout << "Grade: " << grade << ", maximized by dropping assignment ";
    cout << to_drop << "\n";
}

catch (runtime_error& e) {
    cerr << "Caught in main: " << e.what() << endl;
    exit(1);
}

