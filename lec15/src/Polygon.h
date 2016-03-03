#pragma once

#include "Shape.h"

#include <vector>

// A polygon, defined as a sequence of vertex positions.
class Polygon : public Shape
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
        : Shape{bbox(sequence)}
        , vertices_{sequence}
{ }

// Makes a regular polygon with the given center and number of sides, where
// `radius` is the distance from the center to each vertex.
Polygon regular_polygon(Polygon::posn center, double radius, size_t sides);
