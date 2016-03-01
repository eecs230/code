#pragma once

#include "posn.h"

#include <algorithm>
#include <exception>

namespace geometry
{

template <typename T>
class bounding_box
{
public:
    class invalid_exception : public std::exception
    {
        virtual const char* what() const throw() override
        {
            return "Invalid bounding box (type does not have infinity)";
        }
    };

    bounding_box()
    {
        if (std::numeric_limits<T>::has_infinity) {
            top_    = left_   = std::numeric_limits<T>::infinity();
            bottom_ = right_  = -top_;
        } else {
            throw invalid_exception{};
        }
    }

    bounding_box(const T& top, const T& right, const T& bottom,
                 const T& left) noexcept
    {
        if (top > bottom || left > right) {
            bounding_box();
        } else {
            top_    = top;
            right_  = right;
            bottom_ = bottom;
            left_   = left;
        }
    }

    template <typename Boundable>
    bounding_box(std::initializer_list<Boundable> boundables)
            : bounding_box()
    {
        for (const auto& boundable : boundables)
            *this = *this + boundable.get_bounding_box();
    }

    const T& top()    const noexcept { return top_; }
    const T& right()  const noexcept { return right_; }
    const T& bottom() const noexcept { return bottom_; }
    const T& left()   const noexcept { return left_; }

    posn<T> top_left()     const noexcept { return {left(), top()}; }
    posn<T> top_right()    const noexcept { return {right(), top()}; }
    posn<T> bottom_left()  const noexcept { return {left(), bottom()}; }
    posn<T> bottom_right() const noexcept { return {right(), bottom()}; }

    T height() const noexcept { return bottom() - top(); }
    T width()  const noexcept { return right() - left(); }

    bool contains(const posn<T>& p) const noexcept
    {
        return p.x >= left() && p.x < right() && p.y >= top() && p.y < bottom();
    }

    inline const bounding_box& get_bounding_box() const
    {
        return *this;
    }

private:
    T top_, right_, bottom_, left_;
};

// Union
template <typename T>
bounding_box<T>
operator+(const bounding_box<T>& bb1, const bounding_box<T>& bb2)
{
    return bounding_box<T>(std::min(bb1.top(), bb2.top()),
                           std::max(bb1.right(), bb2.right()),
                           std::max(bb1.bottom(), bb2.bottom()),
                           std::min(bb1.left(), bb2.left()));
}

// Intersection
template <typename T>
bounding_box<T>
operator*(const bounding_box<T>& bb1, const bounding_box<T>& bb2)
{
    return bounding_box<T>(std::max(bb1.top(), bb2.top()),
                           std::min(bb1.right(), bb2.right()),
                           std::min(bb1.bottom(), bb2.bottom()),
                           std::max(bb1.left(), bb2.left()));
}

template <typename T, typename Boundable>
bounding_box<T> bound(const Boundable& b)
{
    return b.get_bounding_box();
}

template <typename T, typename Boundable, typename... Boundables>
bounding_box<T> bound(const Boundable& b1, const Boundables&... rest)
{
    return b1.get_bounding_box() + bound<T, Boundables...>(rest...);
}

} // namespace geometry
