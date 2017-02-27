#include <string>

///
/// Polymorphism
///

/*
 * The solution to the problem at the end of animals2.cpp is a *virtual*
 * function. Declaring a function `virtual` in the base class means
 * that we expect the derived classes to *override* it, and we want to
 * get the overridden derived class behavior, even with working with a
 * base class reference. To do this, we change the declaration of
 * `Animal::play` to be virtual:
 */
class Animal
{
public:
    Animal(const std::string& name, unsigned int weight);

    void eat(unsigned int amount);
    virtual void play(); // <<< CHANGE IS HERE

    const std::string& get_name() const { return name_; }
    unsigned int get_weight() const { return weight_; }

    // When using inheritance, the base class *must* have a virtual
    // destructor, even if it doesn't have to do anything.
    virtual ~Animal() { }

private:
    std::string name_;
    unsigned int weight_;
};

/*
 * The `Cat` class remains the same as before because we want `Cat` to have
 * the default `play` behavior inherited from `Animal`.
 */
class Cat : public Animal
{
public:
    Cat(const std::string& name);
    void speak();
};

/*
 * Then in `Dog`, we redefine `play` and indicate that we are overriding
 * the base definition of `play`:
 */
class Dog : public Animal
{
public:
    Dog(const std::string& name);
    void speak();
    void play() override; // <<< OTHER CHANGE IS HERE

private:
    unsigned int nbones_;
};

/*
 * Now when we use a `Dog` object via an `Animal&` reference, it uses
 * `Dog::play` rather than `Animal::play`.
 *
 * This is polymorphic because the `Animal&` does not necessarily refer
 * to an `Animal` object, but different kinds of derived classes with
 * potentially different behaviors.
 *
 * Continue in animals3.h.
 */
