#pragma once

#include "Drawing_decorator.h"

#include <cmath>

// A map from [0, 1] -> [0, 1] (the unit interval) specifying how quickly the
// gradient changes and in what direction.
struct Modulator
{
    using sample = graphics::sample;
    virtual sample modulate(sample) const = 0;
};

// Causes the gradient to change uniformly throughout its range.
struct Linear : Modulator
{
    sample modulate(sample in) const override { return in; }
};

// Causes the gradient to oscillate like a sine wave.
struct Sinusoidal : Modulator
{
    double frequency;   // The number of full waves in the gradient
    double phase;       // Where in the wave to start, 1 being the whole wave

    Sinusoidal(double frequency = 1, double phase = 0)
            : frequency{frequency}
            , phase{phase}
    { }

    sample modulate(sample in) const override
    {
        return 0.5 + 0.5 * sin(2 * M_PI * (frequency * in.value() + phase));
    }
};

// A map from [0, 1] x [0, 1] -> [0, 1], specifying how to collapse the
// 2-D coordinates to a 1-D gradient.
struct Projector
{
    using sample = graphics::sample;
    virtual sample project(sample x, sample y) const = 0;
};

// Makes the gradient change from left to right.
struct Horizontal : Projector
{
    sample project(sample x, sample) const override
    { return x; }
};

// Makes the gradient change from top to bottom.
struct Vertical : Projector
{
    sample project(sample, sample y) const override
    { return y; }
};

// Makes the gradient change from inside to out in concentric same-color
// circles.
struct Circular : Projector
{
    sample project(sample x, sample y) const override
    {
        auto dx = x.value() - 0.5;
        auto dy = y.value() - 0.5;
        return sqrt(2 * (dx*dx + dy*dy));
    }
};

// Adapts a shape to fill it with a color gradient.
class Gradient : public Drawing_decorator
{
public:
    Gradient(drawing_ptr, color start, color end,
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

drawing_ptr gradient(drawing_ptr, Drawing::color start, Drawing::color end,
                     const Projector& = Horizontal{},
                     const Modulator& = Linear{});
