#include "Bst.h"

#include <UnitTest++/UnitTest++.h>

TEST(Empty)
{
    Bst set;
    CHECK_EQUAL(true, set.is_empty());
    CHECK_EQUAL(0, set.size());
}
