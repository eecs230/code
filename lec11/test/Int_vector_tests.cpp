#include "Int_vector.h"

#include <UnitTest++/UnitTest++.h>
#include <iostream>

TEST(NewEmpty)
{
    Int_vector v;
}

TEST(NewWithCapacity)
{
    Int_vector v(16);
}

TEST(PushBack)
{
    Int_vector v;

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

void print_vector(Int_vector w) {
    for (int i = 0; i < w.size(); ++i) {
        std::cout << w[i] << '\n';
    }
} // destructor for w runs here

TEST(Copying)
{
    Int_vector v;
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);

    print_vector(v);

    Int_vector u;
    u.push_back(15);
    u.push_back(16);
    u.push_back(17);
    u.push_back(18);

    print_vector(v);

    v = u;
    print_vector(v);
} // destructors for v and u run here
