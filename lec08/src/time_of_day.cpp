#include "Time_of_day.h"

#include <iomanip>

namespace lec08 {

using namespace std;

Time_of_day::Time_of_day() : Time_of_day{0, 0, 0}
{ }

Time_of_day::Time_of_day(int h, int m, int s)
{
    hours(h);
    minutes(m);
    seconds(s);
}

int Time_of_day::hours()   const { return h_; }

int Time_of_day::minutes() const { return m_; }

int Time_of_day::seconds() const { return s_; }

void Time_of_day::hours(int h)
{
    if (h < 0 || h >= 24) throw Bad_time{};
    h_ = h;
}

void Time_of_day::minutes(int m)
{
    if (m < 0 || m >= 60) throw Bad_time{};
    m_ = m;
}

void Time_of_day::seconds(int s)
{
    if (s < 0 || s >= 60) throw Bad_time{};
    s_ = s;
}

bool operator==(const Time_of_day& t1, const Time_of_day& t2)
{
    return t1.hours() == t2.hours() &&
           t1.minutes() == t2.minutes() &&
           t2.seconds() == t2.seconds();
}

bool operator!=(const Time_of_day& t1, const Time_of_day& t2)
{
    return !(t1 == t2);
}

int seconds_since_midnight(const Time_of_day& t)
{
    return 3600*t.hours() + 60*t.minutes() + t.seconds();
}

Time_of_day operator+(const Time_of_day& t, int seconds)
{
    int ssm = seconds_since_midnight(t) + seconds;
    int s = ssm % 60;
    int m = ssm/60 % 60;
    int h = ssm/3600 % 24;

    return Time_of_day{h, m, s};
}

int operator-(const Time_of_day& t1, const Time_of_day& t2)
{
    return seconds_since_midnight(t1) - seconds_since_midnight(t2);
}

ostream& operator<<(ostream& o, const Time_of_day& t)
{
    return o << t.hours() << ':'
             << setfill('0') << setw(2) << t.minutes() << ':'
             << setfill('0') << setw(2) << t.seconds();
}

} // end lec08
