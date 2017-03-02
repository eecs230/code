#pragma once

#include "Drawing.h"

#include <vector>

// A polygon, defined as a sequence of vertex positions.
class Polygon : public Drawing
{
public:
    // Constructs a polygon with the given vertices.
    Polygon(std::initializer_list<posn> vertices);

    // Constructs a polygon from a sequence of vertices (e.g., a vector).
    template<typename Sequence>
    Polygon(const Sequence&);

    bool contains(posn p) const override;

protected:
    // Provides derived classes access to the sequence of vertices.
    const std::vector<posn>& get_vertices() const;

private:
    std::vector<posn> vertices_;
};

template<typename Sequence>
Polygon::Polygon(const Sequence& sequence)
        : Drawing{bbox(sequence)}
        , vertices_{sequence}
{ }

drawing_ptr polygon(std::initializer_list<Drawing::posn> vertices);

template <typename Sequence>
drawing_ptr polygon(const Sequence& sequence)
{
    return std::make_shared<Polygon>(sequence);
}

// Makes a regular polygon with the given center and number of sides, where
// `radius` is the distance from the center to each vertex.
drawing_ptr regular_polygon(Polygon::posn center, double radius, size_t sides);
