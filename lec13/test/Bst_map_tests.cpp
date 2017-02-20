#include "Bst_map.h"

#include <UnitTest++/UnitTest++.h>
#include <string>

TEST(Script)
{
    using std::string;

    Bst_map<string, int> map;

    CHECK_EQUAL(0, map.size());
    CHECK(!map.contains_key("hello"));

    map.insert("hello", 5);
    map["eecs230"] = 6;

    CHECK_EQUAL(2, map.size());
    CHECK(map.contains_key("hello"));
    CHECK(!map.contains_key("world"));
    CHECK(map.contains_key("eecs230"));

    CHECK_EQUAL(5, *map.find("hello"));
    CHECK(map.find("world") == nullptr);

    map.remove("hello");
    CHECK_EQUAL(1, map.size());
    CHECK(!map.contains_key("hello"));
}
