#include "../src/restorer.h"
#include <catch.h>

TEST_CASE("Restorer")
{
    int z = 0;

    CHECK( 0 == z );

    {
        Restorer<int> restorer(z, 10);
        CHECK( 0 == z );

        z = 5;
        CHECK( 5 == z );
    }

    CHECK( 10 == z );
}

TEST_CASE("Make_restorer")
{
    int z = 0;

    CHECK( 0 == z );

    {
        auto restorer = make_restorer(z);
        CHECK( 0 == z );

        z = 5;
        CHECK( 5 == z );
    }

    CHECK( 0 == z );
}

TEST_CASE("Explicit_rollback")
{
    int z = 0;
    {
        auto restorer = make_restorer(z);
        z = 5;
        restorer.rollback();
        CHECK( z == 0 );

        z = 7;
    }

    CHECK( z == 0 );

}

TEST_CASE("Commit")
{
    int z = 0;
    {
        auto restorer = make_restorer(z);
        z = 5;
        restorer.commit();
        CHECK( 5 == z );
    }
    CHECK( 5 == z );
}

TEST_CASE("Exception_rollback")
{
    int z = 0;

    try {
        auto restorer = make_restorer(z);
        z = 5;
        throw 0;
    } catch (int) {
        CHECK( 0 == z );
    }

    CHECK( 0 == z );
}

TEST_CASE("Assignment")
{
    int y = 0;
    int z = 1;

    {
        auto restorer = make_restorer(y);
        y = 5;
        z = 6;
        restorer = make_restorer(z);
        CHECK( 5 == y );
        CHECK( 6 == z );
        z = 7;
    }
    CHECK( 5 == y );
    CHECK( 6 == z );
}
