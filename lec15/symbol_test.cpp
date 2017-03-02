#include "symbol.h"
#include <UnitTest++/UnitTest++.h>

TEST(Interning)
{
    symbol apple = intern("apple");
    symbol banana = intern("banana");
}

TEST(Equality)
{
    symbol apple1 = intern("apple");
    symbol apple2 = intern("apple");
    symbol banana = intern("banana");

    CHECK_EQUAL(apple1, apple2);
    CHECK(apple1 != banana);
    CHECK(apple2 != banana);
}

TEST(Cleaning)
{
    const std::string* ptr;

    {
        symbol apple1 = intern("apple");
        symbol apple2 = intern("apple");

        ptr = &apple1.name();

        CHECK_EQUAL(ptr, &apple2.name());
    }

    Symbol_table::instance().clean();

    symbol apple = intern("apple");

    // This could fail if the allocator puts the new symbol in the same place
    // as the old symbol, but it's unlikely.
    CHECK(ptr != &apple.name());
}