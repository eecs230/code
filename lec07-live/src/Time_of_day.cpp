#include "Time_of_day.h"

int Time_of_day::hours() const
{
    return hours_;
}

int Time_of_day::minutes() const
{
    return minutes_;
}

int Time_of_day::seconds() const
{
    return seconds_;
}

//bool operator==(const Time_of_day& t1, const Time_of_day& t2)
//{
//    return t1.hours == t2.hours &&
//            t1.minutes == t2.minutes &&
//            t1.seconds == t2.seconds;
//}
//
//bool operator!=(const Time_of_day& t1, const Time_of_day& t2)
//{
//    return !(t1 == t2);
//}
//
//ostream& operator<<(ostream& o, const Time_of_day& t)
//{
//    o << t.hours;
//    o << ':' << setfill('0') << setw(2) << t.minutes;
//    o << ':' << setfill('0') << setw(2) << t.seconds;
//    return o;
//}
//
//int seconds_since_midnight(const Time_of_day& t)
//{
//    return 3600 * t.hours + 60 * t.minutes + t.seconds;
//}
//
//int operator-(const Time_of_day& t1, const Time_of_day& t1)
//{
//    return seconds_since_midnight(t1) - seconds_since_midnight(t2);
//}
