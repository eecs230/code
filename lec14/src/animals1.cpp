/////
///// SEE animals1.h first
/////

// The implementations are here, but the implementations aren't very
// interesting.

#include "animals1.h"
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

// The `Cat` constructor passes its the name to the `Animal` constructor
// along with a starting cat weight.
Cat::Cat(const std::string& name) : Animal(name, 10)
{ }

void Cat::speak()
{
    std::cout << get_name() << " says meow!\n";
}

// The `Dog` constructor has to initialize both the base class `Animal` and
// its own member `nbones_`.
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

// `Dog`’s `play` behavior is different from the base `Animal`’s.
void Dog::play()
{
    Animal::play();
    ++nbones_;
}

// Forward declaration, in case we want to call `play_twice` from `main`.
void play_twice(Animal&);

int main()
{
    // My mom has four cats and two dogs.
    Dog willie("Willie");
    Cat vinny("Vinny");
    Cat francie("Francie");

    willie.play();
    vinny.play();
    francie.eat(2);
}

/*
 * An additional feature of inheritance is a form of polymorphism.
 * Polymorphism is when the same variable (or more abstractly, entity)
 * can come in different forms. In this case, the polymorphism is that
 * a reference or pointer whose type says it’s of the base class can
 * actually refer to an object of any derived class. Here we have a
 * function that takes an `Animal` reference:
 */

void play_twice(Animal& an)
{
    an.play();
    an.play();
}

/*
 * We can use the reference according to the public interface of
 * `Animal`, but at run time, the actual object the reference points to
 * is allowed to be any derived class of `Animal`:
 *
 *    play_twice(willie);
 *    play_twice(vinny);
 *
 * There are two problems with this, however:
 *
 * Because we made `speak` different for the two derived classes and
 * didn’t include it in the base class, we can’t call it via a base
 * class (`Animal`) reference.
 *
 * When we call a function on the base class reference, it uses the
 * base class version of the function. That is, when we say `an.play()`,
 * it uses the `Animal::play` member function rather than `Dog::play`,
 * even when `an` is a `Dog`. In particular, the `nbones_` member
 * variable won’t be incremented when we call `play_twice` on the `Dog`
 * `willie`, even though `Dog::play` increments `nbones_`.
 *
 * For the solution to these problems, see animals2.h.
 */
