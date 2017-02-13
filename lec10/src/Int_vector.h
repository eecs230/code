#pragma once

#include <cstddef>
#include <stdexcept>
#include <initializer_list>

// A vector of `int`s.
class Int_vector
{
    size_t capacity_;
    size_t size_;
    int* data_;
    // Invariants:
    //  - size_ <= capacity_
    //  - capacity_ is the allocation size of data_

public:
    Int_vector();
    Int_vector(size_t initial_capacity);
    Int_vector(std::initializer_list<int> elements);

    // Copy constructor initializing one vector by copying another
    Int_vector(const Int_vector&);

    // Copy-assignment operator, for assigning one vector to another
    Int_vector& operator=(const Int_vector&);

    // Destructor runs when we're done with a vector
    ~Int_vector();

    bool empty() const;
    size_t size() const;

    void push_back(int);
    void pop_back();

    void clear();

    int front() const;
    int& front();
    int back() const;
    int& back();

    int operator[](size_t index) const;
    int& operator[](size_t index);

    int at(size_t index) const;
    int& at(size_t index);

private:
    // Throw if index is out of bounds
    void check_index_(size_t index) const;
    // Make sure there's enough room for `size` elements
    void ensure_capacity_(size_t req_capacity);

public:
    // Forward iterators are pointers to `int`:
    using iterator       = int*;
    using const_iterator = const int*;
    class reverse_iterator;
    class const_reverse_iterator;

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

struct range_error : public std::exception
{ };

bool operator==(const Int_vector&, const Int_vector&);
bool operator!=(const Int_vector&, const Int_vector&);
bool operator< (const Int_vector&, const Int_vector&);
bool operator<=(const Int_vector&, const Int_vector&);
bool operator> (const Int_vector&, const Int_vector&);
bool operator>=(const Int_vector&, const Int_vector&);

/*
 * Below this pointer are the implementations of reverse iterators.
 */

class Int_vector::reverse_iterator
{
public:
    reverse_iterator() : ptr_(nullptr)
    { }

    int& operator*() const
    { return *operator->(); }

    int* operator->() const
    { return ptr_ - 1; }

    int& operator[](ssize_t offset) const
    { return *(ptr_ - 1 - offset); }

    reverse_iterator& operator++()
    { --ptr_; return *this; }

    reverse_iterator operator++(int)
    { return reverse_iterator{ptr_--}; }

    reverse_iterator& operator+=(ssize_t offset)
    { ptr_ -= offset; return *this; }

    reverse_iterator operator+(ssize_t offset)
    { return reverse_iterator{ptr_ - offset}; }

    reverse_iterator& operator--()
    { ++ptr_; return *this; }

    reverse_iterator operator--(int)
    { return reverse_iterator{ptr_++}; }

    reverse_iterator operator-(ssize_t offset)
    { return reverse_iterator{ptr_ + offset}; }

private:
    int* ptr_;
    explicit reverse_iterator(int* p) : ptr_(p) {}

    friend class Int_vector;
    friend class Int_vector::const_reverse_iterator;
};

inline bool
operator==(Int_vector::reverse_iterator a, Int_vector::reverse_iterator b)
{ return &*a == &*b; }

inline bool
operator!=(Int_vector::reverse_iterator a, Int_vector::reverse_iterator b)
{ return &*a != &*b; }

inline bool
operator<(Int_vector::reverse_iterator a, Int_vector::reverse_iterator b)
{ return &*a > &*b; }

inline bool
operator<=(Int_vector::reverse_iterator a, Int_vector::reverse_iterator b)
{ return &*a >= &*b; }

inline bool
operator>(Int_vector::reverse_iterator a, Int_vector::reverse_iterator b)
{ return &*a < &*b; }

inline bool
operator>=(Int_vector::reverse_iterator a, Int_vector::reverse_iterator b)
{ return &*a <= &*b; }

inline Int_vector::reverse_iterator
operator+(ssize_t offset, Int_vector::reverse_iterator iter)
{ return iter + offset; }

inline ssize_t
operator-(Int_vector::reverse_iterator a, Int_vector::reverse_iterator b)
{
    return &*b - &*a;
}

class Int_vector::const_reverse_iterator
{
public:
    const_reverse_iterator() : ptr_(nullptr)
    { }

    const_reverse_iterator(reverse_iterator other)
            : ptr_(other.ptr_)
    { }

    const int& operator*() const
    { return *operator->(); }

    const int* operator->() const
    { return ptr_ - 1; }

    const int& operator[](ssize_t offset) const
    { return *(ptr_ - 1 - offset); }

    const_reverse_iterator& operator++()
    { --ptr_; return *this; }

    const_reverse_iterator operator++(int)
    { return const_reverse_iterator{ptr_--}; }

    const_reverse_iterator& operator+=(ssize_t offset)
    { ptr_ -= offset; return *this; }

    const_reverse_iterator operator+(ssize_t offset)
    { return const_reverse_iterator{ptr_ - offset}; }

    const_reverse_iterator& operator--()
    { ++ptr_; return *this; }

    const_reverse_iterator operator--(int)
    { return const_reverse_iterator{ptr_++}; }

    const_reverse_iterator operator-(ssize_t offset)
    { return const_reverse_iterator{ptr_ + offset}; }

private:
    const int* ptr_;
    explicit const_reverse_iterator(const int* p) : ptr_(p) {}

    friend class Int_vector;
};
inline bool operator==(Int_vector::const_reverse_iterator a, Int_vector::const_reverse_iterator b) { return &*a == &*b; }

inline bool
operator!=(Int_vector::const_reverse_iterator a,
           Int_vector::const_reverse_iterator b)
{ return &*a != &*b; }

inline bool
operator<(Int_vector::const_reverse_iterator a,
          Int_vector::const_reverse_iterator b)
{ return &*a > &*b; }

inline bool
operator<=(Int_vector::const_reverse_iterator a,
           Int_vector::const_reverse_iterator b)
{ return &*a >= &*b; }

inline bool
operator>(Int_vector::const_reverse_iterator a,
          Int_vector::const_reverse_iterator b)
{ return &*a < &*b; }

inline bool
operator>=(Int_vector::const_reverse_iterator a,
           Int_vector::const_reverse_iterator b)
{ return &*a <= &*b; }

inline Int_vector::const_reverse_iterator
operator+(ssize_t offset, Int_vector::const_reverse_iterator iter)
{ return iter + offset; }

inline ssize_t
operator-(Int_vector::const_reverse_iterator a,
          Int_vector::const_reverse_iterator b)
{
    return &*b - &*a;
}
