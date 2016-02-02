// src/Time_of_day.cpp
#include "Time_of_day.h"

#include <iomanip>

using namespace std;

Time_of_day::Time_of_day() : ssm_{0}
{ }

Time_of_day::Time_of_day(int h, int m, int s)
{
    hours(h);
    minutes(m);
    seconds(s);
}

int Time_of_day::hours() const {
    return ssm_ / 3600;
}

int Time_of_day::minutes() const {
    return (ssm_ / 60) % 60;
}

int Time_of_day::seconds() const {
    return ssm_ % 60;
}

bool operator==(const Time_of_day& t1, const Time_of_day& t2)
{
    return t1.hours() == t2.hours() &&
           t1.minutes() == t2.minutes() &&
           t1.seconds() == t2.seconds();
}

bool operator!=(const Time_of_day& t1, const Time_of_day& t2)
{
    return !(t1 == t2);
}

ostream& operator<<(ostream& os, const Time_of_day& t)
{
    os << t.hours() << ':'
    << setfill('0') << setw(2) << t.minutes() << ':'
    << setfill('0') << setw(2) << t.seconds();
    return os;
}

int seconds_since_midnight(const Time_of_day& t)
{
    return 3600 * t.hours() + 60 * t.minutes() + t.seconds();
}

int operator-(const Time_of_day& t1, const Time_of_day& t2)
{
    return seconds_since_midnight(t1) - seconds_since_midnight(t2);
}

void Time_of_day::hours(int h)
{
    if (h < 0 || h >= 24) throw Bad_time{};

    int m = minutes();
    int s = seconds();
    ssm_ = 3600 * h + 60 * m + s;
}

void Time_of_day::minutes(int m)
{
    if (m < 0 || m >= 60) throw Bad_time{};

    int h = hours();
    int s = seconds();
    ssm_ = 3600 * h + 60 * m + s;
}

void Time_of_day::seconds(int s)
{
    if (s < 0 || s >= 60) throw Bad_time{};

    int h = hours();
    int m = minutes();
    ssm_ = 3600 * h + 60 * m + s;

}

