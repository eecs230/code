// test/Time_of_day.cpp
#include "Time_of_day.h"

#include <UnitTest++/UnitTest++.h>

using T = Time_of_day;

TEST(Construction)
{
    T t1{0, 0, 0};
    CHECK_EQUAL(0, t1.hours());
    CHECK_EQUAL(0, t1.minutes());
    CHECK_EQUAL(0, t1.seconds());

    T t2{23, 59, 59};
    CHECK_EQUAL(23, t2.hours());
    CHECK_EQUAL(59, t2.minutes());
    CHECK_EQUAL(59, t2.seconds());

    CHECK_THROW(T(24, 0, 0), Bad_time);
    CHECK_THROW(T(2, 60, 0), Bad_time);
    CHECK_THROW(T(2, -9, 0), Bad_time);
}

TEST(Format)
{
    T t1{12, 41, 33}; // 12:41:33
    T t2{12, 42, 8};  // 12:42:08
    T t3{13, 6, 24};  // 13:06:24

    std::ostringstream os;

    os << t1;
    CHECK_EQUAL("12:41:33", os.str());

    os.str("");
    os << t2;
    CHECK_EQUAL("12:42:08", os.str());

    os.str("");
    os << t3;
    CHECK_EQUAL("13:06:24", os.str());
}

TEST(Equals)
{
    T t1{13, 30, 3};
    T t2{13, 30, 3};
    T t3{14, 30, 3};

    CHECK_EQUAL(t1, t2);
    CHECK_EQUAL(false, t1 == t3);
}

TEST(SecondsSinceMidnight)
{
    CHECK_EQUAL(0, seconds_since_midnight(T{}));
    CHECK_EQUAL(0, seconds_since_midnight(T{0, 0, 0}));
    CHECK_EQUAL(34, seconds_since_midnight(T{0, 0, 34}));
    CHECK_EQUAL(7234, seconds_since_midnight(T{2, 0, 34}));
    CHECK_EQUAL(3600*2 + 60*15 + 34, seconds_since_midnight(T{2, 15, 34}));
}

TEST(Setters)
{
    T t;

    t.hours(18);
    CHECK_EQUAL(T(18, 0, 0), t);

    t.minutes(34);
    CHECK_EQUAL(T(18, 34, 0), t);

    t.minutes(35);
    CHECK_EQUAL(T(18, 35, 0), t);

    t.seconds(59);
    CHECK_EQUAL(T(18, 35, 59), t);

    t.hours(15);
    CHECK_EQUAL((T{15, 35, 59}), t);
}

TEST(SetterErrors)
{
    T t{1, 2, 3};

    CHECK_THROW(t.hours(-2), Bad_time);
    CHECK_THROW(t.hours(-1), Bad_time);
    CHECK_THROW(t.hours(24), Bad_time);
    CHECK_THROW(t.hours(25), Bad_time);

    CHECK_THROW(t.minutes(-2), Bad_time);
    CHECK_THROW(t.minutes(-1), Bad_time);
    CHECK_THROW(t.minutes(60), Bad_time);
    CHECK_THROW(t.minutes(61), Bad_time);

    CHECK_THROW(t.seconds(-2), Bad_time);
    CHECK_THROW(t.seconds(-1), Bad_time);
    CHECK_THROW(t.seconds(60), Bad_time);
    CHECK_THROW(t.seconds(61), Bad_time);
}

TEST(Subtraction)
{
    CHECK_EQUAL(10, T(3, 22, 59) - T(3, 22, 49));
    CHECK_EQUAL(20, T(3, 23, 9) - T(3, 22, 49));
    CHECK_EQUAL(5 * 3600 + -14 * 60 + -40,
              T(8, 8, 9) - T(3, 22, 49));
}


