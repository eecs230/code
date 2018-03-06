#include "../src/matcher.h"
#include <catch.h>

using namespace matcher;

TEST_CASE("Matcher for a")
{
    Matcher m = equals("a");

    CHECK(m->matches("a"));
    CHECK_FALSE(m->matches("b"));

    CHECK(to_string(*m) == "(equals \"a\")");
}

TEST_CASE("Negation matcher")
{
    auto m = !equals("a");

    CHECK_FALSE( m->matches("a") );
    CHECK( m->matches("b") );
}

TEST_CASE("String matchers")
{
    auto m = starts_with("Hello") && (ends_with(".") || ends_with("!"));

    CHECK( m->matches("Hello.") );
    CHECK( m->matches("Hello, EECS 211.") );
    CHECK( m->matches("Hello, EECS 211!") );
    CHECK_FALSE( m->matches("Hello, EECS 211?") );

    CHECK( to_string(*m) == "(and (starts-with \"Hello\") "
                                 "(or (ends-with \".\") "
                                     "(ends-with \"!\")))" );
}
