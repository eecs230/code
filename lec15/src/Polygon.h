#pragma once

#include "Shape.h"

#include <vector>

class Polygon : public Shape
{
public:
    Polygon(std::initializer_list<posn> vertices);

    bool contains(posn p) const override;

protected:
    const std::vector<posn>& get_vertices() const;

private:
    std::vector<posn> vertices_;
};
