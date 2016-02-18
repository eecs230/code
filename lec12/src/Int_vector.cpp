#include <Int_vector.h>
#include <algorithm>
#include <iostream>

constexpr size_t default_initial_capacity = 8;

Int_vector::Int_vector(size_t initial_capacity)
        : capacity_{initial_capacity}
        , size_{0}
        , data_{new int[initial_capacity]}
{ }

Int_vector::Int_vector()
        : Int_vector(default_initial_capacity)
{ }

int Int_vector::at(size_t n) const
{
    check_index_(n);
    return *(data_ + n);
}

int& Int_vector::at(size_t n)
{
    check_index_(n);
    return *(data_ + n);
}

void Int_vector::check_index_(size_t index) const
{
    if (index >= size_) throw range_error{};
}

int Int_vector::operator[](size_t n) const
{
    return *(data_ + n);
}

int& Int_vector::operator[](size_t n)
{
    return *(data_ + n);
}

size_t Int_vector::size() const
{
    return size_;
}

void Int_vector::push_back(int i)
{
    ensure_capacity_(size_ + 1);
    *(data_ + size_) = i;
    ++size_;
}

void Int_vector::ensure_capacity_(size_t req_capacity)
{
    if (req_capacity <= capacity_) return;

    size_t new_capacity = std::max(req_capacity, 2 * capacity_);
    int* new_data       = new int[new_capacity];

    for (int i = 0; i < size_; ++i) {
        *(new_data + i) = *(data_ + i);
    }

    delete[] data_;

    data_     = new_data;
    capacity_ = new_capacity;
}

Int_vector::~Int_vector()
{
    delete[] data_;
}

Int_vector::Int_vector(const Int_vector& old)
        : capacity_{old.capacity_}
        , size_{old.size_}
        , data_{new int[old.capacity_]}
{
    for (size_t i = 0; i < old.size(); ++i) {
        *(data_ + i) = *(old.data_ + i);
    }
}

Int_vector& Int_vector::operator=(const Int_vector& other)
{
    delete[] data_;
    capacity_ = other.capacity_;
    size_     = other.size_;
    data_     = new int[capacity_];

    for (size_t i = 0; i < size_; ++i) {
        *(data_ + i) = *(other.data_ + i);
    }

    return *this;
}
