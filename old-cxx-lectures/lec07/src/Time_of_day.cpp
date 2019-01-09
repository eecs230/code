// src/Time_of_day.cpp
#include "Time_of_day.h"

#include <iomanip>

using namespace std;

Time_of_day::Time_of_day() : hours_{0}, minutes_{0}, seconds_{0}
{ }

Time_of_day::Time_of_day(int h, int m, int s)
{
    hours(h);
    minutes(m);
    seconds(s);
}

int Time_of_day::hours() const {
    return hours_;
}

int Time_of_day::minutes() const {
    return minutes_;
}

int Time_of_day::seconds() const {
    return seconds_;
}

void Time_of_day::hours(int h)
{
    if (h < 0 || h >= 24) throw Bad_time{};

    hours_ = h;
}

void Time_of_day::minutes(int m)
{
    if (m < 0 || m >= 60) throw Bad_time{};

    minutes_ = m;
}

void Time_of_day::seconds(int s)
{
    if (s < 0 || s >= 60) throw Bad_time{};

    seconds_ = s;
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
