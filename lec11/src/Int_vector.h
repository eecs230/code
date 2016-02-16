#pragma once

#include <cstddef>

class Int_vector
{
    size_t capacity_;
    size_t size_;
    int* data_;

public:
    Int_vector();
    Int_vector(size_t capacity);

    size_t size() const;

    int operator[](size_t index) const;
    int& operator[](size_t index);
};
