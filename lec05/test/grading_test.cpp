#include "grading.h"
#include <eecs230.h>

TEST(Total_weight)
{
    vector<Weighted_grade> v{{10, 2}, {12, 3}};
    CHECK_EQUAL(5, total_weight(v));
}

TEST(Weighted_sum)
{
    vector<Weighted_grade> v{{10, 2}, {12, 3}};
    CHECK_EQUAL(56, weighted_sum(v));
}
