#include <sstream>

#include "gtest/gtest.h"

#include "Time_of_day.h"

namespace lec08 {

using T = Time_of_day;

TEST(Time, DefaultConstructor)
{
    T t;

    EXPECT_EQ(0, t.hours());
    EXPECT_EQ(0, t.minutes());
    EXPECT_EQ(0, t.seconds());
}

TEST(Time, ConstructorSuccess)
{
    T t{17, 32, 8};

    EXPECT_EQ(17, t.hours());
    EXPECT_EQ(32, t.minutes());
    EXPECT_EQ(8, t.seconds());

    t = T{23, 59, 59};

    EXPECT_EQ(23, t.hours());
    EXPECT_EQ(59, t.minutes());
    EXPECT_EQ(59, t.seconds());
};

TEST(Time, ConstructorFailure)
{
    EXPECT_THROW(T t(17, 32, 68), Bad_time);
};

TEST(Time, Equals)
{
    EXPECT_EQ(T{}, T{});
    EXPECT_EQ(T(6, 8, 10), T(6, 8, 10));
    EXPECT_NE(T(7, 8, 10), T(6, 8, 10));
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
    EXPECT_EQ(T(15, 35, 59), t);
}

TEST(Time, SetterErrors)
{
    T t{1, 2, 3};

    EXPECT_THROW(t.hours(-2), Bad_time);
    EXPECT_THROW(t.hours(-1), Bad_time);
    EXPECT_THROW(t.hours(25), Bad_time);
    EXPECT_THROW(t.hours(26), Bad_time);
    EXPECT_THROW(t.minutes(-2), Bad_time);
    EXPECT_THROW(t.minutes(-1), Bad_time);
    EXPECT_THROW(t.minutes(60), Bad_time);
    EXPECT_THROW(t.minutes(61), Bad_time);
    EXPECT_THROW(t.seconds(-2), Bad_time);
    EXPECT_THROW(t.seconds(-1), Bad_time);
    EXPECT_THROW(t.seconds(60), Bad_time);
    EXPECT_THROW(t.seconds(61), Bad_time);
}

TEST(Time, SecondsSinceMidnight)
{
    EXPECT_EQ(0, seconds_since_midnight(T{}));
    EXPECT_EQ(34, seconds_since_midnight(T{0, 0, 34}));
    EXPECT_EQ(2*3600 + 34, seconds_since_midnight(T{2, 0, 34}));
    EXPECT_EQ(2*3600 + 15*60 + 34, seconds_since_midnight(T{2, 15, 34}));
}

TEST(Time, Add)
{
    EXPECT_EQ(T(3, 22, 59), T(3, 22, 49) + 10);
    EXPECT_EQ(T(3, 23, 9), T(3, 22, 49) + 20);
    EXPECT_EQ(T(8, 8, 9), T(3, 22, 49) + (4 * 3600 + 45 * 60 + 20));
}

TEST(Time, Subtract)
{
    EXPECT_EQ(10, T(3, 22, 59) - T(3, 22, 49));
    EXPECT_EQ(20, T(3, 23, 9) - T(3, 22, 49));
    EXPECT_EQ(4 * 3600 + 45 * 60 + 20, T(8, 8, 9) - T(3, 22, 49));
}

TEST(Time, Format)
{
    std::ostringstream o;
    o << T{};
    EXPECT_EQ("0:00:00", o.str());

    o.str("");
    o << T{3, 45, 6};
    EXPECT_EQ("3:45:06", o.str());
}

} // end namespace lec08
