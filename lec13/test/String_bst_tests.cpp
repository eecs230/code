#include "String_bst_set.h"

#include <UnitTest++/UnitTest++.h>
#include <sstream>

TEST(Empty)
{
    String_bst_set set;
    CHECK(set.is_empty());
    CHECK_EQUAL(0, set.size());
}

TEST(ContainsEmpty)
{
    String_bst_set set;
    CHECK(!set.contains("5"));
}

TEST(Insert)
{
    String_bst_set set;
    set.insert("2");
    set.insert("4");
    set.insert("6");
    CHECK_EQUAL(3, set.size());
}

TEST(Debug1)
{
    String_bst_set set;
    set.insert("4");
    set.insert("2");
    set.insert("6");

    std::ostringstream o;
    set.debug(o);
    CHECK_EQUAL("((. 2 .) 4 (. 6 .))", o.str());
}

TEST(Debug2)
{
    String_bst_set set;
    set.insert("2");
    set.insert("4");
    set.insert("6");

    std::ostringstream o;
    set.debug(o);
    CHECK_EQUAL("(. 2 (. 4 (. 6 .)))", o.str());
}

TEST(InsertContains)
{
    String_bst_set set;
    set.insert("2");
    set.insert("4");
    set.insert("6");

    CHECK(!set.contains("1"));
    CHECK(set.contains("2"));
    CHECK(!set.contains("3"));
    CHECK(set.contains("4"));
    CHECK(!set.contains("5"));
    CHECK(set.contains("6"));
    CHECK(!set.contains("7"));
}

TEST(Reinsert)
{
    String_bst_set set;

    set.insert("3");
    CHECK_EQUAL(1, set.size());

    set.insert("4");
    CHECK_EQUAL(2, set.size());

    set.insert("4");
    CHECK_EQUAL(2, set.size());

    set.insert("5");
    CHECK_EQUAL(3, set.size());

    set.insert("3");
    CHECK_EQUAL(3, set.size());
}

TEST(InitializerList)
{
    String_bst_set set{"2", "4", "6", "8"};

    CHECK(!set.contains("1"));
    CHECK(set.contains("2"));
    CHECK(!set.contains("3"));
    CHECK(set.contains("4"));
    CHECK(!set.contains("5"));
    CHECK(set.contains("6"));
    CHECK(!set.contains("7"));
    CHECK(set.contains("8"));
    CHECK(!set.contains("9"));

    String_bst_set set2{"4", "2", "1", "3", "6", "5", "7"};

    CHECK(!set.contains("1"));
    CHECK(set.contains("2"));
    CHECK(!set.contains("3"));
    CHECK(set.contains("4"));
    CHECK(!set.contains("5"));
    CHECK(set.contains("6"));
    CHECK(!set.contains("7"));
    CHECK(set.contains("8"));
    CHECK(!set.contains("9"));
}


