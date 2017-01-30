#pragma once

#include <algorithm>
#include <cstddef>
#include <stdexcept>

template <typename Element>
class Vector
{
    size_t capacity_;
    size_t size_;
    Element* data_;

public:
    Vector();
    Vector(size_t initial_capacity);

    Vector(const Vector&);

    // Destructor runs when we're done with a vector
    ~Vector();

    // Copy-assignment operator
    Vector& operator=(const Vector&);

    size_t size() const;

    void push_back(Element);

    const Element& at(size_t index) const;
    Element& at(size_t index);

    const Element& operator[](size_t index) const;
    Element& operator[](size_t index);

    using iterator       = Element*;
    using const_iterator = const Element*;

    iterator begin();
    const_iterator begin() const;

    iterator end();
    const_iterator end() const;

private:
    static constexpr size_t default_initial_capacity = 8;

    // Throw if index is out of bounds
    void check_index_(size_t index) const;
    // Make sure there's enough room for `size` elements
    void ensure_capacity_(size_t req_capacity);
};

struct range_error : public std::exception
{ };

template <typename Element>
Vector<Element>::Vector(size_t initial_capacity)
        : capacity_{initial_capacity}
        , size_{0}
        , data_{new Element[initial_capacity]}
{ }

template <typename Element>
Vector<Element>::Vector()
        : Vector(default_initial_capacity)
{ }

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
size_t Vector<Element>::size() const
{
    return size_;
}

template <typename Element>
void Vector<Element>::push_back(Element e)
{
    ensure_capacity_(size_ + 1);
    *(data_ + size_) = e;
    ++size_;
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
Vector<Element>::~Vector()
{
    delete[] data_;
}

template <typename Element>
Vector<Element>::Vector(const Vector& other)
        : capacity_{other.capacity_}
        , size_{other.size_}
        , data_{new Element[other.capacity_]}
{
    *this = other;
}

template <typename Element>
Vector<Element>& Vector<Element>::operator=(const Vector<Element>& other)
{
    ensure_capacity_(other.size());

    for (size_t i = 0; i < other.size(); ++i) {
        *(data_ + i) = *(other.data_ + i);
    }

    return *this;
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
bool operator==(const Vector<Element>& a, const Vector<Element>& b)
{
    if (a.size() != b.size()) return false;

    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }

    return true;
}

template <typename Element>
typename Vector<Element>::iterator begin(Vector<Element>& v)
{
    return v.begin();
}

template <typename Element>
typename Vector<Element>::const_iterator begin(const Vector<Element>& v)
{
    return v.begin();
}

template <typename Element>
typename Vector<Element>::iterator end(Vector<Element>& v)
{
    return v.end();
}

template <typename Element>
typename Vector<Element>::const_iterator end(const Vector<Element>& v)
{
    return v.end();
}
