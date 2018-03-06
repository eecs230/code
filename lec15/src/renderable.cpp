#include "renderable.h"

namespace renderable {

using namespace graphics;
using namespace std;

class Renderable::Impl
{
public:
    Impl(const bbox& bbox) : bbox_(bbox) { }

    const bbox& get_bbox() const { return bbox_; }

    virtual Color sample(posn) const = 0;

private:
    bbox bbox_;
};

using impl_ptr = shared_ptr<const Renderable::Impl>;

void Renderable::simple_render(graphics::raster& raster)
{
    for (size_t y = 0; y < raster.height(); ++y) {
        for (size_t x = 0; x < raster.width(); ++x) {
            raster.at(x, y) = pimpl_->sample({x + .5, y + .5});
        }
    }
}

void Renderable::render(graphics::raster& raster, unsigned int antialias)
{
    for (size_t y = 0; y < raster.height(); ++y) {
        for (size_t x = 0; x < raster.width(); ++x) {
            graphics::color_blender cb;

            for (unsigned j = 0; j < antialias; ++j) {
                for (unsigned i = 0; i < antialias; ++i) {
                    cb << pimpl_->sample({x + (i + 0.5) / antialias,
                                          y + (j + 0.5) / antialias});
                }
            }

            raster.at(x, y) = cb.get();
        }
    }
}

Renderable::Renderable(shared_ptr<const Renderable::Impl> pimpl)
        : pimpl_(pimpl)
{ }

class Nothing : public Renderable::Impl
{
public:
    Nothing() : Impl(bbox::nothing())
    { }

    Color sample(posn) const override
    {
        return Color::transparent;
    }
};

Renderable::Renderable()
        : pimpl_{make_shared<Nothing>()}
{ }

class Everything : public Renderable::Impl
{
public:
    Everything(const Color& color)
            : Impl(bbox::everything()),
              color_(color)
    { }

    Color sample(posn) const override
    {
        return color_;
    }

private:
    Color color_;
};

Renderable Renderable::everything(const Color& color)
{
    return {make_shared<Everything>(color)};
}

class Abstract_shape : public Renderable::Impl
{
public:
    Abstract_shape(const bbox& bbox, const Color& color)
            : Impl(bbox), color_(color)
    { }

    Color sample(posn p) const override
    {
        return contains(p)? color_ : Color::transparent;
    }

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

Renderable Renderable::circle(posn center, double radius, const Color& color)
{
    return {make_shared<Circle>(center, radius, color)};
}

class Overlay : public Renderable::Impl
{
public:
    Overlay(impl_ptr front, impl_ptr back)
            : Impl(front->get_bbox() + back->get_bbox()),
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
    impl_ptr front_, back_;
};

Renderable Renderable::overlay(Renderable background) const
{
    return {make_shared<Overlay>(pimpl_, background.pimpl_)};
}

Renderable overlay(initializer_list<Renderable> layers)
{
    Renderable result;

    for (Renderable each : layers)
        result = each.overlay(result);

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

Renderable Renderable::rectangle(const bbox& bbox, const Color& color)
{
    return {make_shared<Rectangle>(bbox, color)};
}

class Impl_decorator : public Renderable::Impl
{
public:
    using Dec = Impl_decorator;

    Impl_decorator(impl_ptr base)
            : Impl_decorator(base, base->get_bbox())
    { }

    Impl_decorator(impl_ptr base, const bbox& bbox)
            : Impl(bbox), base_(base)
    { }

    Color sample(posn p) const override
    {
        return base_->sample(p);
    }

protected:
    const impl_ptr base_;
};

class Opacity : public Impl_decorator
{
public:
    Opacity(impl_ptr base, graphics::sample alpha)
            : Dec(base), alpha_(alpha)
    { }

    Color sample(posn p) const override
    {
        return Dec::sample(p).with_alpha(alpha_);
    }

private:
    graphics::sample alpha_;
};

Renderable Renderable::opacity(sample alpha) const
{
    return {make_shared<Opacity>(pimpl_, alpha)};
}

class Transform : public Impl_decorator
{
public:
    Transform(impl_ptr base, const affinity& transform)
            : Dec(base, transform(base->get_bbox())),
              inv_trans_(transform.inverse())
    { }

    Color sample(posn p) const override {
        return Dec::sample(inv_trans_(p));
    }

private:
    affinity inv_trans_;
};

Renderable Renderable::transform(const affinity& transform) const
{
    return {make_shared<Transform>(pimpl_, transform)};
}

Renderable Renderable::at(posn p) const
{
    return transform(affinity::translation(p.x, p.y));
}

class Fill : public Impl_decorator
{
public:
    Fill(impl_ptr base, const Color& color)
            : Dec(base), color_(color)
    { }

private:
    Color sample(posn p) const override
    {
        return compose(color_, Dec::sample(p), composite_mode::in);
        return color_.with_alpha(Dec::sample(p).alpha());
    }

private:
    Color color_;
};

Renderable Renderable::fill(const Color& color) const
{
    return {make_shared<Fill>(pimpl_, color)};
}

}
