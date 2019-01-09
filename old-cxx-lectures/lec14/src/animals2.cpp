// The implementations are here, but the implementations aren't very
// interesting, since they’re the same as in animals1.cpp. You probably
// want animals2.h or if you’ve been there already, animals3.h.

#include "animals2.h"
#include <iostream>

Animal::Animal(const std::string& name, unsigned int weight)
        : name_(name), weight_(weight)
{ }

void Animal::eat(unsigned int amount)
{
    weight_ += amount;
}

void Animal::play()
{
    std::cout << get_name() << " plays.\n";
}

Cat::Cat(const std::string& name) : Animal(name, 10)
{ }

void Cat::speak()
{
    std::cout << get_name() << " says meow!\n";
}

Dog::Dog(const std::string& name)
        : Animal{name, 50}
        , nbones_{1}
{ }

void Dog::speak()
{
    std::cout << get_name() << " says";
    for (int i = 0; i < nbones_; ++i)
        std::cout << " woof";
    std::cout << "!\n";
}

void Dog::play()
{
    Animal::play();
    ++nbones_;
}

// This function uses inheritance polymorphism, since it takes an `Animal`
// reference that might refer to a derived class of `Animal` such as `Dog` or
// `Cat`. Further, because `Animal::play` is virtual, it will use the derived
// class’s version of `play` if the derived class overrides it.
void play_twice(Animal& an)
{
    an.play();
    an.play();
}

/*
 * We can’t do the same for `speak` because `Animal` doesn’t define a `speak`
 * function, so there’s no guarantee that a particular `Animal&` will be from
 * a class that defines `speak`.
 *
 *     void speak_twice(Animal& an)
 *     {
 *         an.speak();
 *         an.speak();
 *     }
 */

int main()
{
    Dog willie("Willie");
    Cat vinny("Vinny");
    Cat francie("Francie");

    play_twice(willie);
    play_twice(vinny);
    francie.eat(2);
    francie.speak();
    willie.speak();
}
