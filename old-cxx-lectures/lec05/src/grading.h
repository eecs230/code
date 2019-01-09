#pragma once

#include <eecs230.h>

struct Weighted_grade
{
    double grade;
    double weight;
};

NEW_RUNTIME_ERROR(average_undefined);

double weighted_average(vector<Weighted_grade>);

vector<Weighted_grade> read_grades();

double weighted_sum(vector<Weighted_grade>);

double total_weight(vector<Weighted_grade>);
