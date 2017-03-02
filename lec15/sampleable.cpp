#include "sampleable.h"

namespace sampleable {

using namespace graphics;
using namespace std;

void Sampleable::simple_render(graphics::raster& raster)
{
    for (size_t y = 0; y < raster.height(); ++y) {
        for (size_t x = 0; x < raster.width(); ++x) {
            raster.at(x, y) = sample({x + .5, y + .5});
        }
    }
}

void Sampleable::render(graphics::raster& raster, unsigned int antialias)
{
    for (size_t y = 0; y < raster.height(); ++y) {
        for (size_t x = 0; x < raster.width(); ++x) {
            graphics::color_blender cb;

            for (unsigned j = 0; j < antialias; ++j) {
                for (unsigned i = 0; i < antialias; ++i) {
                    cb << sample({x + (i + 0.5) / antialias,
                                  y + (j + 0.5) / antialias});
                }
            }

            raster.at(x, y) = cb.get();
        }
    }
}

class Paint : public Sampleable
{
public:
    Paint(const Color& color)
            : Sampleable(bbox::everything()),
              color_(color)
    { }

    Color sample(posn) const override
    {
        return color_;
    }

private:
    Color color_;
};

sampleable_ptr paint(const Color& color)
{
    return make_shared<Paint>(color);
}

class Nothing : public Sampleable
{
public:
    Nothing() : Sampleable(bbox::nothing())
    { }

    Color sample(posn) const override
    {
        return Color::transparent;
    }
};

sampleable_ptr nothing()
{
    return make_shared<Nothing>();
}

class Abstract_shape : public Sampleable
{
public:
    Abstract_shape(const bbox& bbox, const Color& color)
            : Sampleable(bbox), color_(color)
    { }

    Color sample(posn p) const override
    { return contains(p)? color_ : Color::transparent; }

protected:
    virtual bool contains(posn) const = 0;

private:
    Color color_;
};

class Circle : public Abstract_shape
{
public:
    Circle(posn center, double radius, const Color& color)
            : Abstract_shape(bbox_of_circle(center, radius), color),
              center_(center), radius_(radius)
    { }

    bool contains(posn p) const override
    {
        return distance(p, center_) <= radius_;
    }

private:
    const posn center_;
    const double radius_;

    static bbox bbox_of_circle(posn center, double radius)
    {
        return bbox(center.y - radius, center.x + radius,
                    center.y + radius, center.x - radius);
    }
};

sampleable_ptr circle(posn center, double radius, const Color& color)
{
    return make_shared<Circle>(center, radius, color);
}

class Overlay : public Sampleable
{
public:
    Overlay(sampleable_ptr front, sampleable_ptr back)
            : Sampleable(front->get_bbox() + back->get_bbox()),
              front_(front), back_(back)
    { }

    Color sample(posn p) const override
    {
        Color fg;
        bool in_front = front_->get_bbox().contains(p);
        if (in_front) {
            fg = front_->sample(p);
            if (fg.is_opaque()) return fg;
        }

        bool in_back = back_->get_bbox().contains(p);

        if (in_front && in_back) return overlay(fg, back_->sample(p));
        else if (in_front) return front_->sample(p);
        else if (in_back) return back_->sample(p);
        else return Color::transparent;
    }

private:
    sampleable_ptr front_, back_;
};

sampleable_ptr overlay(sampleable_ptr front, sampleable_ptr back)
{
    return make_shared<Overlay>(front, back);
}

sampleable_ptr overlay(initializer_list<sampleable_ptr> layers)
{
    sampleable_ptr result = nothing();

    for (sampleable_ptr each : layers)
        result = overlay(result, each);

    return result;
}

class Rectangle : public Abstract_shape
{
public:
    Rectangle(const bbox& bbox, const Color& color)
            : Abstract_shape(bbox, color)
    { }

    bool contains(posn p) const override
    {
        return get_bbox().contains(p);
    }
};

sampleable_ptr rect_bbox(const bbox& bbox, const Color& color)
{
    return make_shared<Rectangle>(bbox, color);
}

sampleable_ptr rect_trbl(double top, double right, double bottom, double left,
                         const Color& color)
{
    return rect_bbox(bbox(top, right, bottom, left), color);
}

class Sampleable_decorator : public Sampleable
{
public:
    using Dec = Sampleable_decorator;

    Sampleable_decorator(sampleable_ptr base)
            : Sampleable_decorator(base, base->get_bbox())
    { }

    Sampleable_decorator(sampleable_ptr base, const bbox& bbox)
            : Sampleable(bbox), base_(base)
    { }

    Color sample(posn p) const override
    {
        return base_->sample(p);
    }

protected:
    const sampleable_ptr base_;
};

class Opacity : public Sampleable_decorator
{
public:
    Opacity(sampleable_ptr base, graphics::sample alpha)
            : Dec(base), alpha_(alpha)
    { }

    Color sample(posn p) const override
    {
        return apply_alpha(Dec::sample(p));
    }

    Color apply_alpha(const Color& color) const
    {
        return {color.red(), color.green(), color.blue(),
                alpha_ * color.alpha()};
    }

private:
    graphics::sample alpha_;
};

sampleable_ptr opacity(sampleable_ptr base, sample alpha)
{
    return make_shared<Opacity>(base, alpha);
}

class Transform : public Sampleable_decorator
{
public:
    Transform(sampleable_ptr base, const affinity& transform)
            : Dec(base, transform(base->get_bbox())),
              inv_trans_(transform.inverse())
    { }

    Color sample(posn p) const override {
        return Dec::sample(inv_trans_(p));
    }

private:
    affinity inv_trans_;
};

sampleable_ptr transform(sampleable_ptr base, const affinity& transform)
{
    return make_shared<Transform>(base, transform);
}

}
