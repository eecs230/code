#include "Time_of_day.h"

TEST(Time_of_day_stream_insertion)
{
    Time_of_day t1{12, 41, 33};
    Time_of_day t2{12, 42, 8};
    Time_of_day t3{12, 6, 24};

    ostringstream stream;
    stream << t1;
    CHECK_EQUAL("12:41:33", stream.str());

    stream.str("");
    stream << t2;
    CHECK_EQUAL("12:42:08", stream.str());

    stream.str("");
    stream << t3;
    CHECK_EQUAL("12:06:24", stream.str());
}

TEST(Seconds_since_midnight)
{
    CHECK_EQUAL(0, seconds_since_midnight(Time_of_day{0, 0, 0}));
    CHECK_EQUAL(7234, seconds_since_midnight(Time_of_day{2, 0, 34}));
}

TEST(Things_that_make_no_sense)
{
    Time_of_day t1{13, 40, 85};
    Time_of_day t2{14, -19, 15};
}
