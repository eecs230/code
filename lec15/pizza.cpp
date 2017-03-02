#include "pizza.h"
#include <UnitTest++/UnitTest++.h>
#include <vector>

unsigned int Pizza0::total_half_toppings_() const
{
    return (unsigned int)(left_toppings_.size() + right_toppings_.size());
}

unsigned int Pizza0::crust_price_(Pizza0::crust_t crust)
{
    switch (crust) {
        case crust_t::thin:
        case crust_t::regular:
            return 1000;
        case crust_t::thick:
            return 1300;
    }
}

unsigned int Pizza0::price() const
{
    // $10 or $13 (thick) + $0.50/side-topping
    return crust_price_(crust_) + 50 * total_half_toppings_();
}

void Pizza0::bake()
{ }

////
//// Now implementation of the builder version.
////

unsigned int Pizza::total_half_toppings_() const
{
    return (unsigned int)(left_toppings_.size() + right_toppings_.size());
}

unsigned int Pizza::crust_price_(Pizza::crust_t crust)
{
    switch (crust) {
        case crust_t::thin:
        case crust_t::regular:
            return 1000;
        case crust_t::thick:
            return 1300;
    }
}

unsigned int Pizza::price() const
{
    // $10 or $13 (thick) + $0.50/side-topping
    return crust_price_(crust_) + 50 * total_half_toppings_();
}

void Pizza::bake()
{ }

Pizza::Builder& Pizza::Builder::crust(crust_t c)
{
    crust_ = c;

    // Builders often return *this for chaining, a la
    //
    //    builder.crust(c).topping(t1).topping(t2);
    return *this;
}

Pizza::Builder& Pizza::Builder::sauce(sauce_t s, side_t side)
{
    switch (side) {
        case side_t::left:
            left_sauce_ = s;
            break;
        case side_t::right:
            right_sauce_ = s;
            break;
        case side_t::both:
            left_sauce_ = s;
            right_sauce_ = s;
            break;
    }

    return *this;
}

Pizza::Builder& Pizza::Builder::topping(const topping_t& t, side_t side)
{
    switch (side) {
        case side_t::left:
            left_toppings_.push_back(t);
            break;
        case side_t::right:
            right_toppings_.push_back(t);
            break;
        case side_t::both:
            left_toppings_.push_back(t);
            right_toppings_.push_back(t);
            break;
    }

    return *this;
}

Pizza Pizza::Builder::build() const
{
    return Pizza(crust_,
                 left_sauce_, left_toppings_,
                 right_sauce_, right_toppings_);
}

