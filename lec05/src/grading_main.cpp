#include "grading.h"
#include <eecs230.h>

int main()
try {
    vector<Weighted_grade> grades = read_grades();
    double average = weighted_average(grades);
    cout << "Average: " << average << '\n';
}

catch (average_undefined&) {
    cerr << "Average isn't defined for empty data set\n";
}

