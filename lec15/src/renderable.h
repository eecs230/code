#pragma once

#include "graphics.h"

#include <initializer_list>
#include <memory>

namespace sampleable
{

using graphics::Color;

using bbox = graphics::bbox<double>;
using posn = graphics::posn<double>;

class Renderable
{
public:
    // Constructs the empty Renderable:
    Renderable();

    static Renderable everything(const Color&);
    static Renderable circle(posn center, double radius, const Color&);
    static Renderable rectangle(const bbox&, const Color&);

    Renderable overlay(Renderable background) const;
    Renderable transform(const graphics::affinity&) const;
    Renderable opacity(graphics::sample alpha) const;
    Renderable at(posn) const;
    Renderable fill(const Color&) const;

    void simple_render(graphics::raster&);
    void render(graphics::raster&, unsigned antialias = 3);

    class Impl;

private:
    Renderable(std::shared_ptr<const Impl>);

    // invariant: not null
    std::shared_ptr<const Impl> pimpl_;
};

Renderable overlay(std::initializer_list<Renderable>);

}
