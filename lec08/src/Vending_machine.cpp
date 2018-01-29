#include "Vending_machine.h"

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
    balance_ += amount;
}

size_t Vending_machine::select_item(const string& item)
{
    auto price = prices_.find(item);
    auto count = inventory_.find(item);

    if (price == prices_.end()) {
        throw Unknown_item();
    }

    if (count->second == 0) {
        throw Out_of_stock();
    }

    if (price->second > balance_) {
        throw Insufficient_funds();
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

size_t Vending_machine::get_inventory(const string& item)
{
    auto count = inventory_.find(item);

    if (count == inventory_.end()) {
        throw Unknown_item();
    }

    return count->second;
}

size_t Vending_machine::get_price(const string& item)
{
    auto price = prices_.find(item);

    if (price == prices_.end()) {
        throw Unknown_item();
    }

    return price->second;
}

vector<string> Vending_machine::get_items() const
{
    vector<string> result;

    for (const auto& i : prices_) {
        result.push_back(i.first);
    }

    return result;
}

