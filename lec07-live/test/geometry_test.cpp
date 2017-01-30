#include "geometry.h"

using namespace geometry;

TEST(Area_of_circle)
{
    Circle c1{{2, 4}, 3};
    CHECK_CLOSE(9 * M_PI, area(c1), 0.0001);

    Circle c2{{0, 0}, 1};
    CHECK_CLOSE(M_PI, area(c2), 0.0001);
}

TEST(Double_radius)
{
    Circle c1{{2, 4}, 3};
    double_radius(c1);

    Circle expected{{2, 4}, 6};
    CHECK_EQUAL(expected, c1);
}

TEST(Double_radius_fun)
{
    Circle c1{{2, 4}, 3};
    Circle c2 = double_radius_fun(c1);

    Circle expected{{2, 4}, 6};
    CHECK_EQUAL(expected, c2);
}

TEST(Stream_insert_Posn)
{
    Posn p{3, 4};
    ostringstream stream;
    stream << p;
    CHECK_EQUAL("(3, 4)", stream.str());
}

TEST(Distance)
{
    Posn p1{0, 0};
    Posn p2{4, 3};
    CHECK_CLOSE(5, distance(p1, p2), 0.000001);
}
