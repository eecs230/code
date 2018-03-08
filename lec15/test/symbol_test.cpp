#include "symbol.h"
#include <catch.h>

TEST_CASE("Interning")
{
    symbol apple = intern("apple");
    symbol banana = intern("banana");
}

TEST_CASE("Equality")
{
    symbol apple1 = intern("apple");
    symbol apple2 = intern("apple");
    symbol banana = intern("banana");

    CHECK( apple1 == apple2 );
    CHECK(apple1 != banana);
    CHECK(apple2 != banana);
}

TEST_CASE("Cleaning")
{
    const std::string* ptr;

    {
        symbol apple1 = intern("apple");
        symbol apple2 = intern("apple");

        ptr = &apple1.name();

        CHECK( ptr == &apple2.name() );
    }

    Symbol_table::instance().clean();

    symbol apple = intern("apple");

    // This could fail if the allocator puts the new symbol in the same place
    // as the old symbol, but it's unlikely.
    CHECK(ptr != &apple.name());
}
