#include "Vending_machine.h"
#include <eecs230.h>

TEST(Get_balance)
{
    Vending_machine machine;
    CHECK_EQUAL(0, machine.get_balance());
    machine.insert_coin(25);
    CHECK_EQUAL(25, machine.get_balance());
}

TEST(Get_inventory)
{
    Vending_machine machine;
    CHECK_EQUAL(8, machine.get_inventory("Snickers"));
    CHECK_EQUAL(4, machine.get_inventory("Skittles"));
}

TEST(Get_inventory__unknown)
{
    Vending_machine machine;
    CHECK_THROW(machine.get_inventory("Cheetos"), Unknown_item);
}

TEST(Get_price)
{
    Vending_machine machine;
    CHECK_EQUAL(125, machine.get_price("Snickers"));
    CHECK_EQUAL(100, machine.get_price("Skittles"));
}

TEST(Get_price__unknown)
{
    Vending_machine machine;
    CHECK_THROW(machine.get_price("Cheetos"), Unknown_item);
}

TEST(Get_items)
{
    Vending_machine machine;
    vector<string> items = machine.get_items();

    CHECK_EQUAL(2, items.size());
    // In what order?
}

TEST(Insert_coin)
{
    Vending_machine machine;

    machine.insert_coin(25);
    CHECK_EQUAL(25, machine.get_balance());

    machine.insert_coin(10);
    CHECK_EQUAL(35, machine.get_balance());
}

TEST(Select_item)
{
    Vending_machine machine;

    machine.insert_coin(200);
    CHECK_EQUAL(75, machine.select_item("Snickers"));
    CHECK_EQUAL(0, machine.get_balance());
}

TEST(Select_item__unknown)
{
    Vending_machine machine;
    machine.insert_coin(1000);
    CHECK_THROW(machine.select_item("Cheetos"), Unknown_item);
}

TEST(Select_item__insufficent_funds)
{
    Vending_machine machine;
    machine.insert_coin(1);
    CHECK_THROW(machine.select_item("Skittles"), Insufficient_funds);
}

TEST(Select_item__out_of_stock)
{
    Vending_machine machine;

    auto item  = machine.get_items().front();
    auto price = machine.get_price(item);
    auto count = machine.get_inventory(item);

    while (count--) {
        machine.insert_coin(price);
        CHECK_EQUAL(0, machine.select_item(item));
    }

    machine.insert_coin(price);
    CHECK_THROW(machine.select_item(item), Out_of_stock);
}

TEST(Return_change)
{
    Vending_machine machine;

    machine.insert_coin(10);
    CHECK_EQUAL(10, machine.get_balance());
    CHECK_EQUAL(10, machine.return_change());
    CHECK_EQUAL(0, machine.get_balance());
}

