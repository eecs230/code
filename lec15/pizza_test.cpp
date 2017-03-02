#include "pizza.h"
#include <UnitTest++/UnitTest++.h>

TEST(Pizza_no_builder)
{
    Pizza0 pizza1(Pizza0::crust_t::thin,
                  Pizza0::sauce_t::spicy, {},
                  Pizza0::sauce_t::regular, { "olives", "peppers" });
    CHECK_EQUAL(1100, pizza1.price());

    Pizza0 pizza2(Pizza0::crust_t::thick,
                  Pizza0::sauce_t::white, { "garlic", "mushrooms" },
                  Pizza0::sauce_t::spicy, { "pineapple" });
    CHECK_EQUAL(1450, pizza2.price());
}

TEST(Pizza_builder) {
    Pizza::Builder builder;

    Pizza pizza = builder.build();
    CHECK_EQUAL(1000, pizza.price());

    builder.crust(Pizza::crust_t::thick);
    pizza = builder.build();
    CHECK_EQUAL(1300, pizza.price());

    builder.sauce(Pizza::sauce_t::spicy)
           .topping("pineapple", Pizza::side_t::left)
           .topping("mushrooms");
    pizza = builder.build();
    CHECK_EQUAL(1450, pizza.price());
}
