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

struct Sinusoid : Modulator
{
    double frequency;
    double phase;

    Sinusoid(double frequency = 1, double phase = 0)
            : frequency{frequency}
            , phase{phase}
    { }

    sample modulate(sample in) const override
    {
        return 0.5 + 0.5 * sin(2 * M_PI * (frequency * in.value() + phase));
    }
};

struct Shaper
{
    using sample = graphics::sample;
    virtual sample shape(sample x, sample y) const = 0;
};

struct Horizontal : public Shaper
{
    sample shape(sample x, sample) const
    { return x; }
};

struct Vertical : public Shaper
{
    sample shape(sample, sample y) const
    { return y; }
};

struct Circular : public Shaper
{
    sample shape(sample x, sample y) const
    {
        return sqrt((x.value()*x.value() + y.value()*y.value()) / 2);
    }
};

class Gradient : public Shape_decorator
{
public:
    Gradient(const Shape&, color start, color end,
             const Shaper& = Horizontal{},
             const Modulator& = Linear{});

    using sample = graphics::sample;

    color color_at(posn) const override;

protected:
    virtual color color_at(sample, sample) const;
    virtual color color_at(sample) const;

    color            start_;
    color            end_;
    const Modulator& modulator_;
    const Shaper&    shaper_;
};

