#include <string>

///
/// Pure virtual functions
///

/*
 * We did not define a `speak` function in the `Animal` class, since
 * that function is different for the derived classes, and so there was
 * no sharing to be had. But this prevents us from calling `speak` on an
 * `Animal&`, even if the object referred to is actually a `Cat` or
 * `Dog`. It has to be this way because there’s no guarantee of every
 * derived class of `Animal` will define `speak`. We can fix this by
 * declaring in `Animal` that every derived class of `Animal` must
 * define `speak`. We do this by declaring `speak` to be *pure virtual*.
 */

class Animal
{
public:
    Animal(const std::string& name, unsigned int weight);

    void eat(unsigned int amount);
    virtual void play();
    virtual void speak() = 0; // << NEW LINE HERE

    /*
     * The `= 0` means that `Animal` will not define `speak`, but that
     * its derived classes must. In particular, `Animal` is considered an
     * *abstract class* because its definition is incomplete, and this
     * prevents `Animal` objects from being instantiated. However, we
     * define (*override*) `speak` in `Cat` and `Dog`, and this makes
     * those classes concrete and instantiable. See below.
     */

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
 * Class `Cat` inherits from abstract class `Animal`. In order for `Cat` to
 * be a concrete class (in order to create instances of `Cat`), it has to
 * override `Animal`’s pure virtual function `speak`:
 */
class Cat : public Animal
{
public:
    Cat(const std::string& name);
    void speak() override; // << ADDED override HERE
};

/*
 * Class `Dog` also has to override `speak` in order to be concrete.
 */
class Dog : public Animal
{
public:
    Dog(const std::string& name);
    void speak() override; // << ADDED override HERE
    void play() override;

private:
    unsigned int nbones_;
};

/*
 * The function definitions in animals3.cpp remain unchanged. However, see
 * the end of animals3.cpp for how to store `Animal`s in a collection.
 */
