// test/Time_of_day.cpp
#include "Time_of_day.h"

#include <gtest/gtest.h>

using T = Time_of_day;

TEST(Time, Construction)
{
    T t1{0, 0, 0};
    EXPECT_EQ(0, t1.hours());
    EXPECT_EQ(0, t1.minutes());
    EXPECT_EQ(0, t1.seconds());

    T t2{23, 59, 59};
    EXPECT_EQ(23, t2.hours());
    EXPECT_EQ(59, t2.minutes());
    EXPECT_EQ(59, t2.seconds());

    EXPECT_THROW(T t3(24, 0, 0);, Bad_time);
    EXPECT_THROW(T t3(2, 60, 0);, Bad_time);
    EXPECT_THROW(T t3(2, -9, 0);, Bad_time);
}

TEST(Time, Format)
{
    T t1{12, 41, 33}; // 12:41:33
    T t2{12, 42, 8};  // 12:42:08
    T t3{13, 6, 24};  // 13:06:24

    std::ostringstream os;

    os << t1;
    EXPECT_EQ("12:41:33", os.str());

    os.str("");
    os << t2;
    EXPECT_EQ("12:42:08", os.str());

    os.str("");
    os << t3;
    EXPECT_EQ("13:06:24", os.str());
}

TEST(Time, Equals)
{
    T t1{13, 30, 3};
    T t2{13, 30, 3};
    T t3{14, 30, 3};

    EXPECT_EQ(t1, t2);
    EXPECT_NE(t1, t3);
}

TEST(Time, SecondsSinceMidnight)
{
    EXPECT_EQ(0, seconds_since_midnight(T{}));
    EXPECT_EQ(0, seconds_since_midnight(T{0, 0, 0}));
    EXPECT_EQ(34, seconds_since_midnight(T{0, 0, 34}));
    EXPECT_EQ(7234, seconds_since_midnight(T{2, 0, 34}));
    EXPECT_EQ(3600*2 + 60*15 + 34, seconds_since_midnight(T{2, 15, 34}));
}

TEST(Time, Setters)
{
    T t;

    t.hours(18);
    EXPECT_EQ(T(18, 0, 0), t);

    t.minutes(34);
    EXPECT_EQ(T(18, 34, 0), t);

    t.minutes(35);
    EXPECT_EQ(T(18, 35, 0), t);

    t.seconds(59);
    EXPECT_EQ(T(18, 35, 59), t);

    t.hours(15);
    EXPECT_EQ((T{15, 35, 59}), t);
}

TEST(Time, SetterErrors)
{
    T t{1, 2, 3};

    EXPECT_THROW(t.hours(-2), Bad_time);
    EXPECT_THROW(t.hours(-1), Bad_time);
    EXPECT_THROW(t.hours(24), Bad_time);
    EXPECT_THROW(t.hours(25), Bad_time);

    EXPECT_THROW(t.minutes(-2), Bad_time);
    EXPECT_THROW(t.minutes(-1), Bad_time);
    EXPECT_THROW(t.minutes(60), Bad_time);
    EXPECT_THROW(t.minutes(61), Bad_time);

    EXPECT_THROW(t.seconds(-2), Bad_time);
    EXPECT_THROW(t.seconds(-1), Bad_time);
    EXPECT_THROW(t.seconds(60), Bad_time);
    EXPECT_THROW(t.seconds(61), Bad_time);
}

TEST(Time, Subtraction)
{
    EXPECT_EQ(10, T(3, 22, 59) - T(3, 22, 49));
    EXPECT_EQ(20, T(3, 23, 9) - T(3, 22, 49));
    EXPECT_EQ(5 * 3600 + -14 * 60 + -40,
              T(8, 8, 9) - T(3, 22, 49));
}
