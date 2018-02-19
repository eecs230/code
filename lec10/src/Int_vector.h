#pragma once

#include <cstddef>
#include <stdexcept>
#include <initializer_list>
#include <iterator>

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
    // Default constructor: reates a new, empty vector
    Int_vector();

    // Constructor: creates a vector with the given initial capacity allocated
    explicit Int_vector(size_t initial_capacity);

    // Constructor: creates a vector with the given elements
    Int_vector(std::initializer_list<int> elements);

    // Copy constructor: initializes one vector by copying another
    Int_vector(const Int_vector&);

    // Copy-assignment operator: assigns one vector to another
    Int_vector& operator=(const Int_vector&);

    // Destructor: runs when we're done with a vector to free its memory
    ~Int_vector();

    bool empty() const;
    size_t size() const;

    void push_back(int);
    void pop_back();

    void clear();
    void swap(Int_vector&);

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
    using iterator               = int*;
    using const_iterator         = const int*;
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

struct range_error : public std::exception
{ };

void swap(Int_vector&, Int_vector&) noexcept;

bool operator==(const Int_vector&, const Int_vector&);
bool operator!=(const Int_vector&, const Int_vector&);
bool operator< (const Int_vector&, const Int_vector&);
bool operator<=(const Int_vector&, const Int_vector&);
bool operator> (const Int_vector&, const Int_vector&);
bool operator>=(const Int_vector&, const Int_vector&);

