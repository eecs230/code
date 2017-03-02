#pragma once

#include <string>
#include <vector>

/*
 * Class `Pizza0` describes a pizza order. A pizza has a single crust type.
 * For sauces and toppings, they may differ on the left side of the pizza and
 * the right, where each can have one sauce and any number of toppings.
 *
 * Pizza construction is complicated, because we have to pass in five
 * parameters, in the right order, and two of them are vectors we have to
 * build before hand.
 */

class Pizza0
{
public:
    using topping_t = std::string;
    enum class crust_t { thin, regular, thick };
    enum class sauce_t { regular, spicy, white, none };

    using topping_list = std::vector<topping_t>;

    // When we end up with different versions of the constructor for
    // different defaults, this is sometimes known as the telescoping
    // constructor anti-pattern. See the builder pattern below for a fix.
    Pizza0() : Pizza0(crust_t::regular, sauce_t::regular)
    { }

    explicit
    Pizza0(crust_t crust, sauce_t sauce = sauce_t::regular)
            : Pizza0(crust, sauce, {}, sauce, {})
    { }

    Pizza0(crust_t crust,
           sauce_t left_sauce, const topping_list& left_toppings,
           sauce_t right_sauce, const topping_list& right_toppings)
            : crust_(crust),
              left_sauce_(left_sauce), left_toppings_ (left_toppings),
              right_sauce_(right_sauce), right_toppings_(right_toppings)
    { }

    unsigned int price() const;
    void bake();
    // etc.

private:
    crust_t crust_;
    sauce_t left_sauce_, right_sauce_;
    topping_list left_toppings_, right_toppings_;

    unsigned int total_half_toppings_() const;
    static unsigned int crust_price_(crust_t);
};

/*
 * The builder pattern lets us set up a friendlier pizza construction process.
 * Instead, we use a `Pizza::Builder` object to configure the pizza using a
 * friendly interface, and then when we are ready the `Pizza::Builder` object
 * can build the pizza.
 */

class Pizza
{
public:
    using topping_t = std::string;
    enum class crust_t { thin, regular, thick };
    enum class sauce_t { regular, spicy, white, none };

    enum class side_t { left, right, both };

    class Builder
    {
    public:

        // By default the Pizza_builder class builds a regular-crust pizza with
        // regular sauce on both sides and no toppings. Thus, in this case, we
        // don't need to worry about any configuration. Or we can use the
        // configuration functions below to alter the pizza-to-build.
        Builder()
                : crust_(Pizza::crust_t::regular),
                  left_sauce_(Pizza::sauce_t::regular),
                  right_sauce_(Pizza::sauce_t::regular)
        { }

        Builder& crust(Pizza::crust_t);
        Builder& sauce(Pizza::sauce_t, side_t = side_t::both);
        Builder& topping(const Pizza::topping_t&, side_t = side_t::both);

        Pizza build() const;

    private:
        // The builder has enough private state to build in the `Pizza` object.
        // In this case the private state is identical `Pizza`s private state,
        // but this is not always the case.
        crust_t crust_;
        sauce_t left_sauce_, right_sauce_;
        std::vector<topping_t> left_toppings_, right_toppings_;
    };

    unsigned int price() const;
    void bake();
    // etc.

private:
    Pizza(crust_t crust,
          sauce_t left_sauce, const std::vector<topping_t>& left_toppings,
          sauce_t right_sauce, const std::vector<topping_t>& right_toppings)
            : crust_(crust),
              left_sauce_(left_sauce), left_toppings_ (left_toppings),
              right_sauce_(right_sauce), right_toppings_(right_toppings)
    { }

    crust_t crust_;
    sauce_t left_sauce_, right_sauce_;
    std::vector<topping_t> left_toppings_, right_toppings_;

    unsigned int total_half_toppings_() const;
    static unsigned int crust_price_(crust_t);
};

