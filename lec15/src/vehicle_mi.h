#pragma once

#include <cstdlib>

namespace mi {

class Vehicle
{
public:
    virtual ~Vehicle() = default;
};

class Land_vehicle : public virtual Vehicle {};
class Water_vehicle : public virtual Vehicle {};
class Air_vehicle : public virtual Vehicle {};
class Space_vehicle : public virtual Vehicle {};

class Gas_powered_vehicle : public virtual Vehicle {};
class Electric_powered_vehicle : public virtual Vehicle {};
class Nuclear_powered_vehicle : public virtual Vehicle {};

class Gas_powered_land_vehicle
        : public Land_vehicle, public Gas_powered_vehicle { };
class Electric_powered_land_vehicle
        : public Land_vehicle, public Electric_powered_vehicle { };
class Nuclear_powered_land_vehicle
        : public Land_vehicle, public Nuclear_powered_vehicle { };

class Gas_powered_water_vehicle
        : public Water_vehicle, public Gas_powered_vehicle { };
class Electric_powered_water_vehicle
        : public Water_vehicle, public Electric_powered_vehicle { };
class Nuclear_powered_water_vehicle
        : public Water_vehicle, public Nuclear_powered_vehicle { };

class Electric_powered_space_vehicle
        : public Space_vehicle, public Electric_powered_vehicle { };
class Nuclear_powered_space_vehicle
        : public Space_vehicle, public Nuclear_powered_vehicle { };

class Automobile : Gas_powered_land_vehicle { };

class Speed_boat : Gas_powered_water_vehicle { };

class Nuclear_submarine : Nuclear_powered_water_vehicle { };

}
