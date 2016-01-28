// src/Time_of_day.h
#pragma once

#include <iostream>

struct Time_of_day
{
    int hours;
    int minutes;
    int seconds;
};

// Determines whether two `Time_of_day`s are equal.
bool operator==(const Time_of_day&, const Time_of_day&);
bool operator!=(const Time_of_day&, const Time_of_day&);

// Stream insertion for times.
std::ostream& operator<<(std::ostream&, const Time_of_day&);
