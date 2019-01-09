#pragma once

#include "eecs230.h"

NEW_RUNTIME_ERROR(Unknown_item);
NEW_RUNTIME_ERROR(Out_of_stock);
NEW_RUNTIME_ERROR(Insufficient_funds);

class Vending_machine
{
public:
    Vending_machine();

    void insert_coin(size_t amount);
    size_t select_item(const string& item);
    size_t return_change();

    size_t get_balance() const;
    size_t get_inventory(const string& item);
    size_t get_price(const string& item);
    vector<string> get_items() const;

private:
    size_t balance_;
    unordered_map<string, size_t> prices_;
    unordered_map<string, size_t> inventory_;
    // Invariants:
    //  - balance_ >= 0
    //  - the maps have the same keys
};

