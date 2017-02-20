#pragma once

#include <algorithm>
#include <stdexcept>
#include <initializer_list>
#include <iterator>

// A generic vector.
template <typename Element>
class Vector
{
    size_t capacity_;
    size_t size_;
    Element* data_;
    // Invariants:
    //  - size_ <= capacity_
    //  - capacity_ is the allocation size of data_

public:
    // Default constructor: creates a new, empty vector
    Vector();

    // Constructor: creates a vector with the given initial capacity allocated
    explicit Vector(size_t initial_capacity);

    // Constructor: creates a vector with the given elements
    Vector(std::initializer_list<Element> elements);

    // Copy constructor: initializes one vector by copying another
    Vector(const Vector&);

    // Copy-assignment operator: assigns one vector to another
    Vector& operator=(const Vector&);

    // Destructor: runs when we're done with a vector to free its memory
    ~Vector();

    bool empty() const;
    size_t size() const;

    void push_back(const Element&);
    void pop_back();

    void clear();

    const Element& front() const;
    Element& front();
    const Element& back() const;
    Element& back();

    const Element& operator[](size_t index) const;
    Element& operator[](size_t index);

    const Element& at(size_t index) const;
    Element& at(size_t index);

private:
    static constexpr size_t default_initial_capacity = 8;

    // Throw if index is out of bounds
    void check_index_(size_t index) const;

    // Ensure we have enough space for the requested capacity.
    void ensure_capacity_(size_t req_capacity);

public:
    // Forward iterators are pointers to `int`:
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

template <typename T>
bool operator==(const Vector<T>&, const Vector<T>&);

template <typename T>
bool operator!=(const Vector<T>&, const Vector<T>&);

template <typename T>
bool operator< (const Vector<T>&, const Vector<T>&);

template <typename T>
bool operator<=(const Vector<T>&, const Vector<T>&);

template <typename T>
bool operator> (const Vector<T>&, const Vector<T>&);

template <typename T>
bool operator>=(const Vector<T>&, const Vector<T>&);

/////
///// IMPLEMENTATION
///// For templates, the implementation has to go in the header.
/////

template <typename T>
Vector<T>::Vector(size_t initial_capacity)
        : capacity_(initial_capacity)
        , size_(0)
        , data_(new T[initial_capacity])
{ }

template <typename T>
Vector<T>::Vector()
        : Vector(default_initial_capacity)
{ }

template <typename T>
Vector<T>::Vector(std::initializer_list<T> elements)
        : Vector(elements.size())
{
    for (const T& z : elements) push_back(z);
}

template <typename T>
Vector<T>::Vector(const Vector& other)
        : Vector(other.size())
{
    for (const T& z : other) push_back(z);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    clear();
    ensure_capacity_(other.size());
    for (const T& z : other) push_back(z);

    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] data_;
}

template <typename T>
bool Vector<T>::empty() const
{
    return size_ == 0;
}

template <typename T>
size_t Vector<T>::size() const
{
    return size_;
}

template <typename T>
void Vector<T>::push_back(const T& i)
{
    ensure_capacity_(size_ + 1);
    *(data_ + size_) = i;
    ++size_;
}

template <typename T>
void Vector<T>::pop_back()
{
    --size_;
}

template <typename T>
void Vector<T>::clear()
{
    size_ = 0;
}

template <typename T>
const T& Vector<T>::front() const
{
    return *data_;
}

template <typename T>
T& Vector<T>::front()
{
    return *data_;
}

template <typename T>
const T& Vector<T>::back() const
{
    return *(data_ + size_ - 1);
}

template <typename T>
T& Vector<T>::back()
{
    return *(data_ + size_ - 1);
}

template <typename T>
const T& Vector<T>::operator[](size_t n) const
{
    return *(data_ + n);
}

template <typename T>
T& Vector<T>::operator[](size_t n)
{
    return *(data_ + n);
}

template <typename T>
const T& Vector<T>::at(size_t n) const
{
    check_index_(n);
    return *(data_ + n);
}

template <typename T>
T& Vector<T>::at(size_t n)
{
    check_index_(n);
    return *(data_ + n);
}

template <typename T>
auto Vector<T>::begin() -> iterator
{
    return data_;
}

template <typename T>
auto Vector<T>::begin() const -> const_iterator
{
    return data_;
}

template <typename T>
auto Vector<T>::cbegin() const -> const_iterator
{
    return data_;
}

template <typename T>
auto Vector<T>::end() -> iterator
{
    return data_ + size_;
}

template <typename T>
auto Vector<T>::end() const -> const_iterator
{
    return data_ + size_;
}

template <typename T>
auto Vector<T>::cend() const -> const_iterator
{
    return data_ + size_;
}

template <typename T>
auto Vector<T>::rbegin() -> reverse_iterator
{
    return reverse_iterator(end());
}

template <typename T>
auto Vector<T>::rbegin() const -> const_reverse_iterator
{
    return const_reverse_iterator(end());
}

template <typename T>
auto Vector<T>::crbegin() const -> const_reverse_iterator
{
    return const_reverse_iterator(end());
}

template <typename T>
auto Vector<T>::rend() -> reverse_iterator
{
    return reverse_iterator(begin());
}

template <typename T>
auto Vector<T>::rend() const -> const_reverse_iterator
{
    return const_reverse_iterator(begin());
}

template <typename T>
auto Vector<T>::crend() const -> const_reverse_iterator
{
    return const_reverse_iterator(begin());
}

template <typename T>
void Vector<T>::check_index_(size_t index) const
{
    if (index >= size_)
        throw std::range_error("Vector: index out of bounds");
}

template <typename T>
void Vector<T>::ensure_capacity_(size_t req_capacity)
{
    if (req_capacity <= capacity_) return;

    size_t new_capacity = std::max(req_capacity, 2 * capacity_);
    T* new_data       = new T[new_capacity];

    for (size_t i = 0; i < size_; ++i) {
        *(new_data + i) = *(data_ + i);
    }

    delete[] data_;

    data_     = new_data;
    capacity_ = new_capacity;
}

template <typename T>
bool operator==(const Vector<T>& a, const Vector<T>& b)
{
    if (a.size() != b.size()) return false;

    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }

    return true;
}

template <typename T>
bool operator!=(const Vector<T>& a, const Vector<T>& b)
{
    return !(a == b);
}

template <typename T>
bool operator<(const Vector<T>& a, const Vector<T>& b)
{
    size_t limit = std::min(a.size(), b.size());

    for (size_t i = 0; i < limit; ++i) {
        if (a[i] < b[i]) return true;
        if (b[i] < a[i]) return false;
    }

    return a.size() < b.size();
}

template <typename T>
bool operator<=(const Vector<T>& a, const Vector<T>& b)
{
    return !(b < a);
}

template <typename T>
bool operator> (const Vector<T>& a, const Vector<T>& b)
{
    return b < a;
}

template <typename T>
bool operator>=(const Vector<T>& a, const Vector<T>& b)
{
    return !(a < b);
}
