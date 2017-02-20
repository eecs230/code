#pragma once

#include <algorithm>
#include <initializer_list>
#include <iterator>
#include <string>

// A vector of ints. See Vector.h for a generic version of this.
class String_vector
{
    size_t capacity_;
    size_t size_;
    std::string* data_;
    // Invariants:
    //  - size_ <= capacity_
    //  - capacity_ is the allocation size of data_

public:
    // Default constructor: creates a new, empty vector
    String_vector();

    // Constructor: creates a vector with the given initial capacity allocated
    explicit String_vector(size_t initial_capacity);

    // Constructor: creates a vector with the given elements
    String_vector(std::initializer_list<std::string> elements);

    // Copy constructor: initializes one vector by copying another
    String_vector(const String_vector&);

    // Copy-assignment operator: assigns one vector to another
    String_vector& operator=(const String_vector&);

    // Destructor: runs when we're done with a vector to free its memory
    ~String_vector();

    bool empty() const;
    size_t size() const;

    void push_back(const std::string&);
    void pop_back();

    void clear();

    const std::string& front() const;
    std::string& front();
    const std::string& back() const;
    std::string& back();

    const std::string& operator[](size_t index) const;
    std::string& operator[](size_t index);

    const std::string& at(size_t index) const;
    std::string& at(size_t index);

private:
    static constexpr size_t default_initial_capacity = 8;

    // Throw if index is out of bounds
    void check_index_(size_t index) const;

    // Ensure we have enough space for the requested capacity.
    void ensure_capacity_(size_t req_capacity);

public:
    // Forward iterators are pointers to `int`:
    using iterator               = std::string*;
    using const_iterator         = const std::string*;
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

bool operator==(const String_vector&, const String_vector&);
bool operator!=(const String_vector&, const String_vector&);
bool operator< (const String_vector&, const String_vector&);
bool operator<=(const String_vector&, const String_vector&);
bool operator> (const String_vector&, const String_vector&);
bool operator>=(const String_vector&, const String_vector&);
