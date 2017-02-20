#include "String_int_dict.h"

#include <UnitTest++/UnitTest++.h>
#include <string>

using namespace std;
using namespace dictionary;

TEST(Member_empty)
{
    String_int_dict dict;
    CHECK(!dict.has_key("a"));
}

TEST(Find_not_found_is_null)
{
    String_int_dict dict;
    CHECK(dict.find("a") == nullptr);
}

TEST(Insert_first_element_then_lookup)
{
    String_int_dict dict;
    dict.insert("b", 5);

    CHECK(!dict.has_key("a"));
    CHECK(dict.has_key("b"));
    CHECK_EQUAL(5, dict["b"]);
}

TEST(Insert_several)
{
    String_int_dict dict;
    dict.insert("d", 4);
    dict.insert("b", 2);
    dict.insert("a", 1);

    CHECK(dict.has_key("a"));
    CHECK(dict.has_key("b"));
    CHECK(!dict.has_key("c"));
    CHECK(dict.has_key("d"));
    CHECK(!dict.has_key("e"));
    CHECK(!dict.has_key("f"));
    CHECK(!dict.has_key("g"));

    dict.insert("c", 3);
    dict.insert("f", 6);
    dict.insert("e", 5);
    dict.insert("g", 7);

    CHECK(dict.has_key("a"));
    CHECK(dict.has_key("b"));
    CHECK(dict.has_key("c"));
    CHECK(dict.has_key("d"));
    CHECK(dict.has_key("e"));
    CHECK(dict.has_key("f"));
    CHECK(dict.has_key("g"));
    CHECK(!dict.has_key(""));
    CHECK(!dict.has_key("ax"));
    CHECK(!dict.has_key("bx"));
    CHECK(!dict.has_key("cx"));
    CHECK(!dict.has_key("dx"));
    CHECK(!dict.has_key("ex"));
    CHECK(!dict.has_key("fx"));
    CHECK(!dict.has_key("gx"));

    CHECK_EQUAL(1, dict["a"]);
    CHECK_EQUAL(2, dict["b"]);
    CHECK_EQUAL(3, dict["c"]);
    CHECK_EQUAL(4, dict["d"]);
    CHECK_EQUAL(5, dict["e"]);
    CHECK_EQUAL(6, dict["f"]);
    CHECK_EQUAL(7, dict["g"]);

    CHECK(dict.find("h") == nullptr);

    int* e = dict.find("e");
    CHECK_EQUAL(5, *e);

    *e = 105;
    CHECK_EQUAL(105, dict["e"]);

    CHECK_EQUAL(0, dict["h"]);
}

