#pragma once

#include <eecs230.h>

// Represents a time of the day.
class Time_of_day
{
public:
    int hours() const;
    int minutes() const;
    int seconds() const;

private:
    int hours_;
    int minutes_;
    int seconds_;
};

bool operator==(const Time_of_day&, const Time_of_day&);
bool operator!=(const Time_of_day&, const Time_of_day&);
ostream& operator<<(ostream&, const Time_of_day&);

// The number of seconds since midnight.
int seconds_since_midnight(const Time_of_day&);

// Computes the number of seconds between two times of the day.
int operator-(const Time_of_day&, const Time_of_day&);
