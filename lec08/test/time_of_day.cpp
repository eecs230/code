// src/Time_of_day.cpp
#include "Time_of_day.h"

#include <iomanip>

using namespace std;

bool operator==(const Time_of_day& t1, const Time_of_day& t2)
{
    return t1.hours == t2.hours &&
           t1.minutes == t2.minutes &&
           t1.seconds == t2.seconds;
}

bool operator!=(const Time_of_day& t1, const Time_of_day& t2)
{
    return !(t1 == t2);
}

ostream& operator<<(ostream& os, const Time_of_day& t)
{
    os << t.hours << ':'
       << setfill('0') << setw(2) << t.minutes << ':'
       << setfill('0') << setw(2) << t.seconds;
    return os;
}
