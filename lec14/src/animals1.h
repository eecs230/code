/////
///// START HERE
/////

#include <string>

///
/// Inheritance
///

/*
 * C++ provides a mechanism for defining families of classes that are
 * similar in some ways and different in others. For example, suppose
 * we want classes to represent different kinds of pet animal, which
 * have operations like sleeping and playing. We can combine their
 * common behavior into a base class and then derive the specific
 * animal classes from that.
 *
 * Let’s call the base class Animal. We’ll initially define it as
 * follows:
 */

class Animal
{
public:
    Animal(const std::string& name, unsigned int weight);

    void eat(unsigned int amount);
    void play();

    const std::string& get_name() const { return name_; }
    unsigned int get_weight() const { return weight_; }

private:
    std::string name_;
    unsigned int weight_;
};

/*
 * That is, every animal has a name and a weight, and has operations to
 * eat and to play. The implementations of the operations are in
 * animals1.cpp.
 *
 * We then *derive* other classes from the `Animal` class. Deriving
 * makes the new class like the old class, but then lets us add to or
 * change it. Here’s `Cat`:
 */

class Cat : public Animal
{
public:
    Cat(const std::string& name);
    void speak();
};

/*
 * The notation `: public Animal` means that `Cat` starts out as a copy
 * of `Animal`, with all of `Animal`’s public members public in `Cat` as
 * well. We then define a constructor, which takes a name and passes it
 * on to the base class’s constructor, along with a fixed weight of 10.
 *
 * `Cat` also has a new member function, `speak`, that `Animal` does not
 * have.
 *
 * We also define `Dog` by deriving from `Animal`, but unlike `Cat`,
 * `Dog`’s playing behavior is a bit more complicated. In particular,
 * each `Dog` has some number of bones, and each time we play the dog
 * gets a new bone. And then when the dog speaks, it says “woof”
 * repeatedly, once for each of its bones. Here’s the definition of the
 * `Dog` class:
 */

class Dog : public Animal
{
public:
    Dog(const std::string& name);
    void speak();
    void play();

private:
    unsigned int nbones_;
};

/*
 * As you can see, `Dog` adds a member variable `nbones_` to `Animal`,
 * adds a member function `speak`, and replaces the base class’s
 * `Animal::play` function with a `Dog`-specific `play` function. The
 * `Dog::play` function delegates to `Animal::play` to do the playing
 * and also increments `nbones_`.
 *
 * Now we can write a program involving cats and dogs. See the bottom of
 * animals1.cpp for main and an introduction to inheritance polymorphism.
 */
