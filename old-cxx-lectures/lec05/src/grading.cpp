#include "grading.h"
#include <eecs230.h>

// Reads in the grades and weights and returns them.
vector<Weighted_grade> read_grades()
{
    vector<Weighted_grade> result;
    Weighted_grade wg;

    while (cin >> wg.grade >> wg.weight) {
        result.push_back(wg);
    }

    return result;
}

// Sums the products of weights and grades.
double weighted_sum(vector<Weighted_grade> grades)
{
    double total = 0;

    for (Weighted_grade wg : grades)
        total += wg.weight * wg.grade;

    return total;
}

// Sums the weights.
double total_weight(vector<Weighted_grade> grades)
{
    double total = 0;

    for (Weighted_grade wg : grades)
        total += wg.weight;

    return total;
}

// Computes a weighted average of the given grades and weights.
double weighted_average(vector<Weighted_grade> grades)
{
    double numerator = weighted_sum(grades);
    double denominator = total_weight(grades);

    if (denominator == 0) {
        throw average_undefined();
    }

    return numerator / denominator;
}

