#include "../src/restorer.h"
#include <UnitTest++/UnitTest++.h>

TEST(Restorer)
{
    int z = 0;

    CHECK_EQUAL(0, z);

    {
        Restorer<int> restorer(z, 10);
        CHECK_EQUAL(0, z);

        z = 5;
        CHECK_EQUAL(5, z);
    }

    CHECK_EQUAL(10, z);
}

TEST(Make_restorer)
{
    int z = 0;

    CHECK_EQUAL(0, z);

    {
        auto restorer = make_restorer(z);
        CHECK_EQUAL(0, z);

        z = 5;
        CHECK_EQUAL(5, z);
    }

    CHECK_EQUAL(0, z);
}

TEST(Explicit_rollback)
{
    int z = 0;
    {
        auto restorer = make_restorer(z);
        z = 5;
        restorer.rollback();
        CHECK_EQUAL(z, 0);

        z = 7;
    }

    CHECK_EQUAL(z, 0);

}

TEST(Commit)
{
    int z = 0;
    {
        auto restorer = make_restorer(z);
        z = 5;
        restorer.commit();
        CHECK_EQUAL(5, z);
    }
    CHECK_EQUAL(5, z);
}

TEST(Exception_rollback)
{
    int z = 0;

    try {
        auto restorer = make_restorer(z);
        z = 5;
        throw 0;
    } catch (int) {
        CHECK_EQUAL(0, z);
    }

    CHECK_EQUAL(0, z);
}

TEST(Assignment)
{
    int y = 0;
    int z = 1;

    {
        auto restorer = make_restorer(y);
        y = 5;
        z = 6;
        restorer = make_restorer(z);
        CHECK_EQUAL(5, y);
        CHECK_EQUAL(6, z);
        z = 7;
    }
    CHECK_EQUAL(5, y);
    CHECK_EQUAL(6, z);
}
