#include "Vector.h"

#include <UnitTest++/UnitTest++.h>
#include <iostream>

TEST(NewEmpty)
{
    Vector<int> v;
}

TEST(NewWithCapacity)
{
    Vector<int> v(16);
}

TEST(PushBack)
{
    Vector<int> v;

    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    v.push_back(13);

    CHECK_EQUAL(5, v[0]);
    CHECK_EQUAL(6, v[1]);
    CHECK_EQUAL(7, v[2]);
    CHECK_EQUAL(13, v[8]);
}

void print_vector(Vector<int> w) {
    for (int d : w) {
        std::cout << d << '\n';
    }
}

TEST(Copying)
{
    Vector<int> v;
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);

    print_vector(v);

    Vector<int> u{v};
    u.push_back(15);
    u.push_back(16);
    u.push_back(17);
    u.push_back(18);

    print_vector(v);
}
