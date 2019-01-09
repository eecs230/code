#pragma once

#include <cstdlib>
#include <memory>

namespace bridge {

class Engine
{
public:
    virtual ~Engine() = default;
};

class Vehicle
{
public:
    Vehicle(std::unique_ptr<Engine> engine)
            : engine_(std::move(engine))
    { }

    virtual ~Vehicle() = default;

    Engine& get_engine() {
        return *engine_;
    }

private:
    const std::unique_ptr<Engine> engine_;
};

class Land_vehicle : public Vehicle {
public:
    Land_vehicle(std::unique_ptr<Engine> engine)
            : Vehicle(std::move(engine))
    {}
};

class Water_vehicle : public Vehicle {
public:
    Water_vehicle(std::unique_ptr<Engine> engine)
            : Vehicle(std::move(engine))
    {}
};

class Air_vehicle : public Vehicle {
public:
    Air_vehicle(std::unique_ptr<Engine> engine)
            : Vehicle(std::move(engine))
    {}
};

class Space_vehicle : public Vehicle {
public:
    Space_vehicle(std::unique_ptr<Engine> engine)
            : Vehicle(std::move(engine))
    {}
};

class Gas_powered_engine : public Engine {};
class Electric_powered_engine : public Engine {};
class Nuclear_powered_engine : public Engine {};

class Automobile : Land_vehicle {
public:
    Automobile()
            : Land_vehicle(std::make_unique<Gas_powered_engine>())
    {}
};

class Speed_boat : Water_vehicle {
    Speed_boat()
            : Water_vehicle(std::make_unique<Gas_powered_engine>())
    {}
};

class Nuclear_submarine : Water_vehicle {
    Nuclear_submarine()
            : Water_vehicle(std::make_unique<Nuclear_powered_engine>())
    { }
};

}
