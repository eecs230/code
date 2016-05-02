#include "Vending_machine.h"

#include <cassert>

const char* Unknown_item::what() const
{
    return "Item not found.";
}

const char* Out_of_stock::what() const
{
    return "Item out of stock.";
}

const char* Insufficient_funds::what() const
{
    return "Insufficient funds to purchase item.";
}

Vending_machine::Vending_machine()
{
    balance_ = 0;

    prices_["Snickers"] = 125;
    inventory_["Snickers"] = 8;

    prices_["Skittles"] = 100;
    inventory_["Skittles"] = 4;
}

void Vending_machine::insert_coin(size_t amount)
{
    assert(amount > 0);
    balance_ += amount;
}

size_t Vending_machine::select_item(const std::string& item)
{
    auto price = prices_.find(item);
    auto count = inventory_.find(item);

    if (price == std::end(prices_)) {
        throw Unknown_item{};
    }

    if (*count == 0) {
        throw Out_of_stock{};
    }

    if (price->second > balance_) {
        throw Insufficient_funds{};
    }

    size_t change = balance_ - price->second;

    balance_ = 0;
    --count->second;

    return change;
}

size_t Vending_machine::return_change()
{
    size_t change = balance_;
    balance_ = 0;
    return change;
}

size_t Vending_machine::get_balance() const
{
    return balance_;
}

size_t Vending_machine::get_inventory(const std::string& item)
{
    auto count = inventory_.find(item);

    if (count == std::end(inventory_)) {
        throw Unknown_item{};
    }

    return count->second;
}

size_t Vending_machine::get_price(const std::string& item)
{
    auto price = prices_.find(item);

    if (price == std::end(prices_)) {
        throw Unknown_item{};
    }

    return price->second;
}

std::vector<std::string> Vending_machine::get_items() const
{
    std::vector<std::string> result;

    for (const auto& i : prices_) {
        result.push_back(i.first);
    }

    return result;
}


