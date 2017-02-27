#include "animals3.h"

#include <iostream>
#include <memory>
#include <vector>

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

void play_twice(Animal& an)
{
    an.play();
    an.play();
}

/*
 * In C++, inheritance polymorphism works only through references and
 * pointers, because base classes and derived classes may have different
 * sizes. That is, you cannot have an `Animal` variable that actual contains
 * a `Cat` or `Dog` objects. (Actually, because `Animal` is abstract now, you
 * cannot have `Animal` variable at all.) However, you can have an `Animal&`
 * that actually refers to a `Dog` or a `Cat`, and similarly for pointer types.
 *
 * Collection types like vectors usually depend on storing elements directly,
 * but that's a problem for inheritance because a std::vector<Animal> can't
 * store `Cat`s and `Dog`s. But a std::shared_ptr<Animal> *can* point to a
 * `Cat` or a `Dog` on the free store. So we can make a vector of shared
 * pointers to `Animal`s, where each pointer actually points to a concrete
 * derived class of `Animal`.
 */

using animal_ptr = std::shared_ptr<Animal>;
using Animal_vec = std::vector<animal_ptr>;

Animal_vec get_animals()
{
    Animal_vec animals;
    animals.push_back(std::make_shared<Dog>("Willie"));
    animals.push_back(std::make_shared<Cat>("Vinny"));
    animals.push_back(std::make_shared<Cat>("Francie"));
    return animals;
}

/*
 * We can `push_back` a `shared_ptr<Cat>` into a vector of
 * `shared_ptr<Animal>` because `shared_ptr` is specially designed to work
 * with inheritance. If we have a vector of shared pointers to `Animal`s, we
 * can use the pointers, even though we don’t know what kind of `Animal` each
 * pointer points to.
 */

void example1()
{
    Animal_vec animals = get_animals();
    for (animal_ptr an : animals) an->speak();
    for (animal_ptr an : animals) play_twice(*an);
    for (animal_ptr an : animals) an->speak();
}

/*
 * It’s possible to convert in the other direction, from a shared pointer to
 * a base class into a shared pointer to a derived class, but the conversion
 * is partial, because it can only happen if the pointer actually is pointing
 * to the desired derived class. Below, we show how to attempt to convert a
 * `shared_ptr<Animal>` into a `shared_ptr<Cat>` using
 * `std::dynamic_pointer_cast`. The cast returns `nullptr` if the shared
 * pointer doesn’t actually point to a `Cat`.
 */

void feed_only_cats(const Animal_vec& animals, unsigned int amount)
{
    std::cout << "Feeding " << amount << " to each cat.\n";
    for (animal_ptr an : animals) {
        std::shared_ptr<Cat> cat = std::dynamic_pointer_cast<Cat>(an);
        if (cat != nullptr) cat->eat(amount);
    }
}

void census(const Animal_vec& animals)
{
    for (animal_ptr an : animals)
        std::cout << an->get_name() << " weighs " << an->get_weight() << ".\n";
}

void example2()
{
    Animal_vec animals = get_animals();

    census(animals);
    feed_only_cats(animals, 1);
    census(animals);
}

int main()
{
    example1();
    example2();
}
