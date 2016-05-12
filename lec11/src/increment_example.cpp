#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <UnitTest++/UnitTest++.h>

static bool is_even(long n)
{
    return (n / 2) * 2 == n;
}

class Even_number
{
    long n_;

public:
    Even_number() : n_{0} {}

    Even_number(long n) : n_{n}
    {
        if (! is_even(n)) throw std::runtime_error("not even");
    }

    long get() const { return n_; }

    void set(long n)
    {
        if (! is_even(n)) throw std::runtime_error("not even");

        n_ = n;
    }
};

Even_number operator+(Even_number a, Even_number b)
{
    return Even_number{a.get() + b.get()};
}

// ++e
Even_number& operator++(Even_number& a)
{
    a.set(a.get() + 2);
    return a;
}

// e++
Even_number operator++(Even_number& a, int)
{
    Even_number old = a;
    ++a;
    return old;
}

std::ostream& operator<<(std::ostream& o, Even_number n)
{
    return o << n.get();
}

std::istream& operator>>(std::istream& i, Even_number& n)
{
    long new_value;
    i >> new_value;
    n.set(new_value);
    return i;
}

TEST(StreamInsertion)
{
    Even_number n{6}, m{8};

    std::ostringstream o;
    o << n << ' ' << m;
    CHECK_EQUAL("6 8", o.str());
}

TEST(StreamExtraction)
{
    Even_number n{6}, m{8};

    std::istringstream i{"88 34"};
    i >> n >> m;
    CHECK_EQUAL(88, n.get());
    CHECK_EQUAL(34, m.get());
}

TEST(Constructor)
{
    CHECK_THROW(Even_number{5}, std::runtime_error);
}

