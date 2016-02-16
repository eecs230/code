#include "Int_vector.h"

#include <UnitTest++/UnitTest++.h>

TEST(NewEmpty)
{
    Int_vector v;
}

TEST(SizeOfEmpty)
{
    CHECK_EQUAL(0, Int_vector{}.size());
}
