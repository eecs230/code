#pragma once

#include <iostream>
#include <stdexcept>

namespace lec08 {

// Represents a valid time in terms of hours, minutes, and seconds.
class Time_of_day
{
public:
    // Constructs midnight
    Time_of_day();

    // Constructs the specified time; throws `Bad_time` if hours is not
    // between 0 and 23, or if minutes or seconds is not between 0 and 59.
    Time_of_day(int hours, int minutes, int seconds);

    // Getters

    int hours() const;

    int minutes() const;

    int seconds() const;

    // Setters (throw `Bad_time`)

    void hours(int);

    void minutes(int);

    void seconds(int);

private:
    int h_, m_, s_;
};

// Two times are equal if all three components are equal
bool operator==(const Time_of_day&, const Time_of_day&);

bool operator!=(const Time_of_day&, const Time_of_day&);

// The number of seconds since midnight
int seconds_since_midnight(const Time_of_day&);

// Returns a time `seconds` later than the given time; wraps past midnight.
Time_of_day operator+(const Time_of_day&, int seconds);

// Returns the number of seconds between two times on the same day.
int operator-(const Time_of_day&, const Time_of_day&);

// Formats a time for output
std::ostream& operator<<(std::ostream&, const Time_of_day&);

// Exception thrown when trying to set an invalid time
struct Bad_time : std::exception { };

} // end lec08
