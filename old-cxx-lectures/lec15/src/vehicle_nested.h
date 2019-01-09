#pragma once

#include <cstdlib>

namespace nested {

class Vehicle
{
public:
    virtual ~Vehicle() = default;
};

class Land_vehicle : public Vehicle {};
class Water_vehicle : public Vehicle {};
class Air_vehicle : public Vehicle {};
class Space_vehicle : public Vehicle {};

class Gas_powered_land_vehicle : public Land_vehicle {};
class Electric_powered_land_vehicle : public Land_vehicle {};
class Nuclear_powered_land_vehicle : public Land_vehicle {};

class Gas_powered_water_vehicle : public Water_vehicle {};
class Electric_powered_water_vehicle : public Water_vehicle {};
class Nuclear_powered_water_vehicle : public Water_vehicle {};

class Electric_powered_space_vehicle : public Space_vehicle {};
class Nuclear_powered_space_vehicle : public Space_vehicle {};

class Automobile : Gas_powered_land_vehicle {};

class Speed_boat : Gas_powered_water_vehicle {};

class Nuclear_submarine : Nuclear_powered_water_vehicle {};

}
