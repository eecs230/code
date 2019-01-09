#include "Pair.h"
#include <UnitTest++/UnitTest++.h>
#include <string>

TEST(Construct)
{
    Pair<int, double> p(4, 5.5);

    CHECK_EQUAL(4, p.first);
    CHECK_EQUAL(5.5, p.second);
}

TEST(Compare)
{
    Pair<int, double> p1(4, 5.5);
    Pair<int, double> p2(4, 5.7);
    Pair<int, double> p3(5, 3);

    CHECK(!(p1 < p1));
    CHECK(p1 < p2);
    CHECK(p1 < p3);
    CHECK(!(p2 < p1));
    CHECK(!(p2 < p2));
    CHECK(p2 < p3);
    CHECK(!(p3 < p1));
    CHECK(!(p3 < p2));
    CHECK(!(p3 < p3));
}

TEST(Generic)
{
    Pair<std::string, char> p1("goodbye", 'd');
    Pair<std::string, char> p2("hello", 'b');
    Pair<std::string, char> p3("hello", 'c');

    CHECK(!(p1 < p1));
    CHECK(p1 < p2);
    CHECK(p1 < p3);
    CHECK(!(p2 < p1));
    CHECK(!(p2 < p2));
    CHECK(p2 < p3);
    CHECK(!(p3 < p1));
    CHECK(!(p3 < p2));
    CHECK(!(p3 < p3));
}
