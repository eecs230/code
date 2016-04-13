#include "Bst.h"

#include <UnitTest++/UnitTest++.h>

TEST(Empty)
{
    Bst<int> set;
    CHECK_EQUAL(true, set.is_empty());
    CHECK_EQUAL(0, set.size());
}

TEST(LongExample)
{
    Bst<int> set;

    CHECK_EQUAL(0, set.size());
    set.insert(5);
    CHECK_EQUAL(1, set.size());
    set.insert(6);
    CHECK_EQUAL(2, set.size());
    set.insert(5);
    CHECK_EQUAL(2, set.size());

    CHECK_EQUAL(true, set.contains(5));
    CHECK_EQUAL(true, set.contains(6));
    CHECK_EQUAL(false, set.contains(7));

    set.remove(6);
    CHECK_EQUAL(1, set.size());
    CHECK_EQUAL(true, set.contains(5));
    CHECK_EQUAL(false, set.contains(6));
    CHECK_EQUAL(false, set.contains(7));
}
