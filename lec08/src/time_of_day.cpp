#include "Time_of_day.h"
#include "gtest/gtest.h"

TEST(Time, Equals)
{
    Time_of_day t1{13, 30, 3};
    Time_of_day t2{13, 29, 63};
    Time_of_day t3{14, 30, 3};

    EXPECT_EQ(t1, t2);
    EXPECT_NE(t1, t3);
}
