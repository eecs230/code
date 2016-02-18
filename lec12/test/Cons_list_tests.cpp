#include "Cons_list.h"

using namespace cons_list;

#include <UnitTest++/UnitTest++.h>

TEST(ConstructEmpty)
{
    Cons_list mt;
}

TEST(EmptyTrue)
{
    Cons_list mt;
    CHECK_EQUAL(true, mt == nullptr);
}

//TEST(ConstructPair)
//{
//    Cons_list lst{"hello", empty};
//}
//
//TEST(EmptyFalse)
//{
//    String_list lst{"hello", empty};
//    CHECK_EQUAL(false, lst.is_empty());
//}
//
//TEST(ConsFirstRest)
//{
//    auto lst = cons("hello", cons("world", empty));
//    CHECK_EQUAL("hello", lst.first());
//    CHECK_EQUAL("world", lst.rest().first());
//    CHECK_EQUAL(true, lst.rest().rest().is_empty());
//}
//
//TEST(Length)
//{
//    auto lst = cons("a", cons("b", cons("c", empty)));
//    CHECK_EQUAL(3, length(lst));
//    CHECK_EQUAL(2, length(lst.rest()));
//    CHECK_EQUAL(1, length(lst.rest().rest()));
//    CHECK_EQUAL(0, length(lst.rest().rest().rest()));
//}
//
//TEST(Sharing)
//{
//    auto a = cons("common", cons("tail", empty));
//    auto b = cons("three", cons("more", cons("nodes", a)));
//    auto c = cons("three total nodes", a);
//
//    CHECK_EQUAL(2, length(a));
//    CHECK_EQUAL(5, length(b));
//    CHECK_EQUAL(3, length(c));
//}
