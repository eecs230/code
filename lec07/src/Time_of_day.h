// src/Time_of_day.h
#pragma once

#include <iostream>
#include <stdexcept>

struct Bad_time : std::exception { };

class Time_of_day
{
public:
    // Constructors:
    Time_of_day();
    Time_of_day(int hours, int minutes, int seconds);

    // Getters/observers:
    int hours() const;
    int minutes() const;
    int seconds() const;

    // Setters/mutators:
    void hours(int);
    void minutes(int);
    void seconds(int);

private:
    int hours_;
    int minutes_;
    int seconds_;
};

// Determines whether two `Time_of_day`s are equal.
bool operator==(const Time_of_day&, const Time_of_day&);
bool operator!=(const Time_of_day&, const Time_of_day&);

// Stream insertion for times.
std::ostream& operator<<(std::ostream&, const Time_of_day&);

// Gets the number of seconds since midnight
int seconds_since_midnight(const Time_of_day&);

// Returns the number of seconds between two times on the same
// day.
int operator-(const Time_of_day&, const Time_of_day&);

