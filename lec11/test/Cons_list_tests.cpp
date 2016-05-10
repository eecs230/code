#include "Cons_list.h"

#include <UnitTest++/UnitTest++.h>
#include <vector>

using namespace cons_list;

TEST(ConstructPair)
{
    auto lst = cons("hello", nullptr);
}

TEST(ConsFirstRest)
{
    auto lst = cons("hello", cons("world", nullptr));
    CHECK_EQUAL("hello", first(lst));
    CHECK_EQUAL("world", first(rest(lst)));
    CHECK_EQUAL(true, rest(rest(lst)) == nullptr);
}

TEST(Sharing)
{
    auto a = cons("common", cons("tail", nullptr));
    auto b = cons("three", cons("more", cons("nodes", a)));
    auto c = cons("three total nodes", a);

    CHECK_EQUAL(2, length(a));
    CHECK_EQUAL(5, length(b));
    CHECK_EQUAL(3, length(c));

    auto d = append(a, b);
    CHECK_EQUAL("common", first(d));
    CHECK_EQUAL("tail",   first(rest(d)));
    CHECK_EQUAL("three",  first(rest(rest(d))));
    CHECK_EQUAL("more",   first(rest(rest(rest(d)))));
    CHECK_EQUAL("nodes",  first(rest(rest(rest(rest(d))))));
    CHECK_EQUAL("common", first(rest(rest(rest(rest(rest(d)))))));
    CHECK_EQUAL("tail",   first(rest(rest(rest(rest(rest(rest(d))))))));
}

TEST(Equality)
{
    CHECK_EQUAL(cons("a", cons("b", nullptr)),
                cons("a", cons("b", nullptr)));
}

TEST(Reverse)
{
    CHECK_EQUAL(cons("c", cons("b", cons("a", nullptr))),
                reverse(cons("a", cons("b", cons("c", nullptr)))));
}

TEST(Iterator)
{
    auto a = cons("1", cons("2", cons("3", nullptr)));
    std::vector<std::string> v;

    for (auto s : a) v.push_back(s);

    CHECK_EQUAL(3, v.size());
    CHECK_EQUAL("1", v[0]);
    CHECK_EQUAL("2", v[1]);
    CHECK_EQUAL("3", v[2]);
}
