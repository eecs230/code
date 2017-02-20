// A generic vector class.

#pragma once

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <stdexcept>

template <typename Element>
class Vector
{
public:
    Vector();
    explicit Vector(size_t initial_capacity);
    Vector(std::initializer_list<Element>);
    Vector(const Vector&);

    // Destructor runs when we're done with a vector
    ~Vector();

    // Copy-assignment operator
    Vector& operator=(const Vector&);

    bool empty() const;
    size_t size() const;

    void clear();

    void push_back(const Element&);
    void pop_back();

    const Element& front() const;
    Element& front();
    const Element& back() const;
    Element& back();

    const Element& operator[](size_t index) const;
    Element& operator[](size_t index);

    const Element& at(size_t index) const;
    Element& at(size_t index);

private:
    size_t capacity_;
    size_t size_;
    Element* data_;

    static constexpr size_t default_initial_capacity = 8;

    // Throw if index is out of bounds
    void check_index_(size_t index) const;

    // Make sure there's enough room for `size` elements
    void ensure_capacity_(size_t req_capacity);

public:
    using iterator               = Element*;
    using const_iterator         = const Element*;
    using reverse_iterator       = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    iterator begin();
    const_iterator begin() const;
    const_iterator cbegin() const;

    iterator end();
    const_iterator end() const;
    const_iterator cend() const;

    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator crbegin() const;

    reverse_iterator rend();
    const_reverse_iterator rend() const;
    const_reverse_iterator crend() const;
};

template <typename Element>
bool operator==(const Vector<Element>&, const Vector<Element>&);

template <typename Element>
bool operator!=(const Vector<Element>&, const Vector<Element>&);

template <typename Element>
bool operator<(const Vector<Element>&, const Vector<Element>&);

template <typename Element>
bool operator<=(const Vector<Element>&, const Vector<Element>&);

template <typename Element>
bool operator>(const Vector<Element>&, const Vector<Element>&);

template <typename Element>
bool operator>=(const Vector<Element>&, const Vector<Element>&);

struct range_error : public std::exception
{ };

//
// IMPLEMENTATIONS
// When using template, implementations have to go in the header!
//

template <typename Element>
Vector<Element>::Vector()
        : Vector(default_initial_capacity)
{ }

template <typename Element>
Vector<Element>::Vector(size_t initial_capacity)
        : capacity_(initial_capacity)
        , size_(0)
        , data_(new Element[initial_capacity])
{ }

template <typename Element>
Vector<Element>::Vector(std::initializer_list<Element> elements)
        : Vector(elements.size())
{
    for (const Element& e : elements) push_back(e);
}

// To copy-construct a vector, we initialize the new vector to have a
// capacity equal to the other vector's size, and then assign it to this vector.
template <typename Element>
Vector<Element>::Vector(const Vector& other)
        : capacity_(other.size_)
        , size_(other.size_)
        , data_(new Element[other.size_])
{
    *this = other;
}

template <typename Element>
Vector<Element>::~Vector()
{
    delete[] data_;
}

template <typename Element>
Vector<Element>& Vector<Element>::operator=(const Vector<Element>& other)
{
    clear();
    ensure_capacity_(other.size());

    for (size_t i = 0; i < other.size(); ++i)
        push_back(other[i]);

    return *this;
}

template <typename Element>
bool Vector<Element>::empty() const
{
    return size_ == 0;
}

template <typename Element>
size_t Vector<Element>::size() const
{
    return size_;
}

template <typename Element>
void Vector<Element>::clear()
{
    size_ = 0;
}

template <typename Element>
void Vector<Element>::push_back(const Element& e)
{
    ensure_capacity_(size_ + 1);
    *(data_ + size_) = e;
    ++size_;
}

template <typename Element>
void Vector<Element>::pop_back()
{
    --size_;
}

template <typename Element>
const Element& Vector<Element>::front() const
{
    return *data_;
}

template <typename Element>
Element& Vector<Element>::front()
{
    return *data_;
}

template <typename Element>
const Element& Vector<Element>::back() const
{
    return *(data_ + size_ - 1);
}

template <typename Element>
Element& Vector<Element>::back()
{
    return *(data_ + size_ - 1);
}

template <typename Element>
const Element& Vector<Element>::operator[](size_t n) const
{
    return *(data_ + n);
}

template <typename Element>
Element& Vector<Element>::operator[](size_t n)
{
    return *(data_ + n);
}

template <typename Element>
const Element& Vector<Element>::at(size_t n) const
{
    check_index_(n);
    return *(data_ + n);
}

template <typename Element>
Element& Vector<Element>::at(size_t n)
{
    check_index_(n);
    return *(data_ + n);
}

template <typename Element>
void Vector<Element>::check_index_(size_t index) const
{
    if (index >= size_) throw range_error{};
}

template <typename Element>
void Vector<Element>::ensure_capacity_(size_t req_capacity)
{
    if (req_capacity <= capacity_) return;

    size_t new_capacity = std::max(req_capacity, 2 * capacity_);
    Element* new_data       = new Element[new_capacity];

    for (int i = 0; i < size_; ++i) {
        *(new_data + i) = *(data_ + i);
    }

    delete[] data_;

    data_     = new_data;
    capacity_ = new_capacity;
}

template <typename Element>
typename Vector<Element>::iterator Vector<Element>::begin()
{
    return data_;
}

template <typename Element>
typename Vector<Element>::const_iterator Vector<Element>::begin() const
{
    return data_;
}

template <typename Element>
typename Vector<Element>::const_iterator Vector<Element>::cbegin() const
{
    return begin();
}

template <typename Element>
typename Vector<Element>::iterator Vector<Element>::end()
{
    return data_ + size_;
}

template <typename Element>
typename Vector<Element>::const_iterator Vector<Element>::end() const
{
    return data_ + size_;
}

template <typename Element>
typename Vector<Element>::const_iterator Vector<Element>::cend() const
{
    return end();
}

// The next several functions use trailing return type syntax. Instead of
// writing:
//
//   int f() { ... }
//
// we can write:
//
//   auto f() -> int { ... }
//
// The difference is that the trailing return type is interpreted in the
// context of the class that the function is a member of, rather than in
// global scope. So for example, for this first function, we can write the
// return type as just reverse_iterator instead of
// Vector<Element>::reverse_iterator.

template <typename Element>
auto Vector<Element>::rbegin() -> reverse_iterator
{
    return reverse_iterator(end());
}

template <typename Element>
auto Vector<Element>::rbegin() const -> const_reverse_iterator
{
    return const_reverse_iterator(end());
}

template <typename Element>
auto Vector<Element>::crbegin() const -> const_reverse_iterator
{
    return const_reverse_iterator(end());
}

template <typename Element>
auto Vector<Element>::rend() -> reverse_iterator
{
    return reverse_iterator(begin());
}

template <typename Element>
auto Vector<Element>::rend() const -> const_reverse_iterator
{
    return const_reverse_iterator(begin());
}

template <typename Element>
auto Vector<Element>::crend() const -> const_reverse_iterator
{
    return const_reverse_iterator(begin());
}

//
// Implementations of free functions
//

template <typename Element>
bool operator==(const Vector<Element>& a, const Vector<Element>& b)
{
    if (a.size() != b.size()) return false;

    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }

    return true;
}

template <typename Element>
bool operator!=(const Vector<Element>& a, const Vector<Element>& b)
{
    return !(a == b);
}

template <typename Element>
bool operator<(const Vector<Element>& a, const Vector<Element>& b)
{
    size_t limit = std::min(a.size(), b.size());

    for (size_t i = 0; i < limit; ++i)
    {
        if (a[i] < b[i]) return true;
        if (b[i] < a[i]) return false;
    }

    return a.size() < b.size();
}

template <typename Element>
bool operator<=(const Vector<Element>& a, const Vector<Element>& b)
{
    return !(b < a);
}

template <typename Element>
bool operator>(const Vector<Element>& a, const Vector<Element>& b)
{
    return b < a;
}

template <typename Element>
bool operator>=(const Vector<Element>& a, const Vector<Element>& b)
{
    return b <= a;
}

