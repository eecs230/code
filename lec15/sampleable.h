#pragma once

#include "graphics.h"

#include <initializer_list>
#include <memory>

namespace sampleable
{

using graphics::Color;

using bbox = graphics::bbox<double>;
using posn = graphics::posn<double>;

class Sampleable
{
public:
    Sampleable(const bbox& bbox) : bbox_(bbox)
    { }

    const bbox& get_bbox() const { return bbox_; }

    virtual Color sample(posn) const = 0;

    void simple_render(graphics::raster&);
    void render(graphics::raster&, unsigned antialias = 3);

private:
    bbox bbox_;
};

using sampleable_ptr = std::shared_ptr<Sampleable>;

sampleable_ptr paint(const Color&);
sampleable_ptr nothing();

sampleable_ptr circle(posn center, double radius, const Color&);
sampleable_ptr rect_bbox(const bbox&, const Color&);
sampleable_ptr rect_trbl(double top, double right, double bottom, double left,
                         const Color&);

sampleable_ptr overlay(sampleable_ptr front, sampleable_ptr back);
sampleable_ptr overlay(std::initializer_list<sampleable_ptr>);

sampleable_ptr opacity(sampleable_ptr, graphics::sample alpha);
sampleable_ptr transform(sampleable_ptr, const graphics::affinity&);

}
