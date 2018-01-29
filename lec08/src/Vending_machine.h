#pragma once

#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

class Vending_machine
{
public:
    Vending_machine();

    void insert_coin(size_t amount);
    size_t select_item(const std::string& item);
    size_t return_change();

    size_t get_balance() const;
    size_t get_inventory(const std::string& item);
    size_t get_price(const std::string& item);
    std::vector<std::string> get_items() const;

private:
    size_t balance_;
    std::unordered_map<std::string, size_t> prices_;
    std::unordered_map<std::string, size_t> inventory_;
    // Invariants:
    //  - balance_ >= 0
    //  - the maps have the same keys
};

struct Vending_exception : std::exception
{ };

struct Unknown_item : Vending_exception
{
    virtual const char* what() const noexcept override;
};

struct Out_of_stock : Vending_exception
{
    virtual const char* what() const noexcept override;
};

struct Insufficient_funds : Vending_exception
{
    virtual const char* what() const noexcept override;
};

