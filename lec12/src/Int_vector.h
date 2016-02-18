#pragma once

#include <cstddef>
#include <stdexcept>

class Int_vector
{
    size_t capacity_;
    size_t size_;
    int* data_;

public:
    Int_vector();
    Int_vector(size_t initial_capacity);

    Int_vector(const Int_vector&);
    Int_vector& operator=(const Int_vector&);

    // Destructor runs when we're done with a vector
    ~Int_vector();

    size_t size() const;

    void push_back(int);

    int at(size_t index) const;
    int& at(size_t index);

    int operator[](size_t index) const;
    int& operator[](size_t index);

private:
    // Throw if index is out of bounds
    void check_index_(size_t index) const;
    // Make sure there's enough room for `size` elements
    void ensure_capacity_(size_t req_capacity);
};

struct range_error : public std::exception
{ };
