#pragma once

#include "Shape_decorator.h"

#include <cmath>

struct Modulator
{
    using sample = graphics::sample;
    virtual sample modulate(sample) const = 0;
};

struct Linear : Modulator
{
    sample modulate(sample in) const override { return in; }
};

struct Sinusoidal : Modulator
{
    double frequency;
    double phase;

    Sinusoidal(double frequency = 1, double phase = 0)
            : frequency{frequency}
            , phase{phase}
    { }

    sample modulate(sample in) const override
    {
        return 0.5 + 0.5 * sin(2 * M_PI * (frequency * in.value() + phase));
    }
};

struct Projector
{
    using sample = graphics::sample;
    virtual sample project(sample x, sample y) const = 0;
};

struct Horizontal : public Projector
{
    sample project(sample x, sample) const
    { return x; }
};

struct Vertical : public Projector
{
    sample project(sample, sample y) const
    { return y; }
};

struct Circular : public Projector
{
    sample project(sample x, sample y) const
    {
        auto dx = x.value() - 0.5;
        auto dy = y.value() - 0.5;
        return sqrt(2 * (dx*dx + dy*dy));
    }
};

class Gradient : public Shape_decorator
{
public:
    Gradient(const Shape&, color start, color end,
             const Projector& = Horizontal{},
             const Modulator& = Linear{});

    using sample = graphics::sample;

    color color_at(posn) const override;

protected:
    virtual color color_at(sample, sample) const;
    virtual color color_at(sample) const;

    color            start_;
    color            end_;
    const Modulator& modulator_;
    const Projector& projector_;
};

