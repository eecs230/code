#include "Int_vector.h"

#include <UnitTest++/UnitTest++.h>
#include <iostream>

TEST(New_empty)
{
    Int_vector v;
}

TEST(New_with_capacity)
{
    Int_vector v(16);
}

TEST(Initializer_list)
{
    Int_vector v{1, 2, 3};

    CHECK_EQUAL(3, v.size());
    CHECK_EQUAL(1, v[0]);
    CHECK_EQUAL(2, v[1]);
    CHECK_EQUAL(3, v[2]);
}

TEST(Copy_constructor)
{
    Int_vector u{1, 2, 3};
    Int_vector v(u);
    Int_vector w(v);

    CHECK(u == w);

    v[0] = 5;
    CHECK(u == w);
    CHECK(u != v);
}

TEST(Assignment_operator)
{
    Int_vector v{1, 2, 3};
    Int_vector w;

    CHECK(v != w);
    w = v;
    CHECK(v == w);
    w.push_back(4);
    CHECK(v != w);
    w = v;
    CHECK(v == w);
}

TEST(Empty)
{
    Int_vector v;
    CHECK(v.empty());
    v.push_back(0);
    CHECK(!v.empty());
}

TEST(Size)
{
    Int_vector v;
    CHECK_EQUAL(0, v.size());
    v.push_back(1);
    CHECK_EQUAL(1, v.size());
    v.push_back(2);
    CHECK_EQUAL(2, v.size());
    v.push_back(3);
    CHECK_EQUAL(3, v.size());
    v.push_back(4);
    CHECK_EQUAL(4, v.size());
}

TEST(Push_back)
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

TEST(Pop_back)
{
    Int_vector v{1, 2, 3};
    CHECK_EQUAL(3, v.size());
    v.pop_back();
    CHECK_EQUAL(2, v.size());
    v.pop_back();
    CHECK_EQUAL(1, v.size());
    v.pop_back();
    CHECK_EQUAL(0, v.size());
}

TEST(Clear)
{
    Int_vector v{1, 2, 3};
    CHECK_EQUAL(3, v.size());
    v.clear();
    CHECK_EQUAL(0, v.size());
    v.push_back(4);
    CHECK_EQUAL(1, v.size());
}

TEST(Front_const)
{
    const Int_vector v{1, 2, 3};
    CHECK_EQUAL(1, v.front());
}

TEST(Front_assign)
{
    Int_vector v{1, 2, 3};
    CHECK_EQUAL(1, v.front());
    v.front() = 10;
    CHECK_EQUAL(10, v.front());
}

TEST(Back_const)
{
    const Int_vector v{1, 2, 3};
    CHECK_EQUAL(3, v.back());
}

TEST(Back_assign)
{
    Int_vector v{1, 2, 3};
    CHECK_EQUAL(3, v.back());
    v.back() = 10;
    CHECK_EQUAL(10, v.back());
}

TEST(Index_const)
{
    const Int_vector v{1, 2, 3};
    CHECK_EQUAL(1, v[0]);
    CHECK_EQUAL(2, v[1]);
    CHECK_EQUAL(3, v[2]);
}

TEST(Index_assign)
{
    Int_vector v{1, 2, 3};
    CHECK_EQUAL(1, v[0]);
    CHECK_EQUAL(2, v[1]);
    CHECK_EQUAL(3, v[2]);

    v[1] = 10;

    CHECK_EQUAL(1, v[0]);
    CHECK_EQUAL(10, v[1]);
    CHECK_EQUAL(3, v[2]);
}

TEST(At_const)
{
    const Int_vector v{1, 2, 3};
    CHECK_EQUAL(1, v.at(0));
    CHECK_EQUAL(2, v.at(1));
    CHECK_EQUAL(3, v.at(2));
    CHECK_THROW(v.at(3), range_error);
}

TEST(At_assign)
{
    Int_vector v{1, 2, 3};
    CHECK_EQUAL(1, v.at(0));
    CHECK_EQUAL(2, v.at(1));
    CHECK_EQUAL(3, v.at(2));

    v.at(1) = 10;

    CHECK_EQUAL(1, v.at(0));
    CHECK_EQUAL(10, v.at(1));
    CHECK_EQUAL(3, v.at(2));
}

TEST(Iteration)
{
    Int_vector v;
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);

    auto i = std::begin(v);
    auto j = std::end(v);
    CHECK(i != j);
    CHECK_EQUAL(5, *i);

    ++i;
    CHECK(i != j);
    CHECK_EQUAL(6, *i);

    ++i;
    CHECK(i != j);
    CHECK_EQUAL(7, *i);

    ++i;
    CHECK(i != j);
    CHECK_EQUAL(8, *i);

    ++i;
    CHECK_EQUAL(j, i);
}

TEST(Comparisons)
{
    Int_vector u{1, 2, 3};
    Int_vector v{1, 2, 3, 4};
    Int_vector w{1, 4, 3};

    CHECK(!(u < u));
    CHECK(u < v);
    CHECK(u < w);
    CHECK(!(v < u));
    CHECK(!(v < v));
    CHECK(v < w);
    CHECK(!(w < u));
    CHECK(!(w < v));
    CHECK(!(w < w));

    CHECK(u <= u);
    CHECK(u <= v);
    CHECK(u <= w);
    CHECK(!(v <= u));
    CHECK(v <= v);
    CHECK(v <= w);
    CHECK(!(w <= u));
    CHECK(!(w <= v));
    CHECK(w <= w);

    CHECK(!(u > u));
    CHECK(!(u > v));
    CHECK(!(u > w));
    CHECK(v > u);
    CHECK(!(v > v));
    CHECK(!(v > w));
    CHECK(w > u);
    CHECK(w > v);
    CHECK(!(w > w));

    CHECK(u >= u);
    CHECK(!(u >= v));
    CHECK(!(u >= w));
    CHECK(v >= u);
    CHECK(v >= v);
    CHECK(!(v >= w));
    CHECK(w >= u);
    CHECK(w >= v);
    CHECK(w >= w);
}
