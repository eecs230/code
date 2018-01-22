#include <eecs230.h>

// Reads in grades and their weights, then prints the weighted average.
int main()
{
    double total_weight = 0;
    double weighted_sum = 0;

    double grade, weight;

    while (cin >> grade >> weight) {
        weighted_sum += weight * grade;
        total_weight += weight;
    }

    if (total_weight == 0) {
        cerr << "Average isn't defined for empty data set\n";
        exit(1);
    }

    cout << "Average: " << weighted_sum / total_weight << '\n';
};