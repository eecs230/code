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

Int_vector::Int_vector(const Int_vector& other)
        : capacity_{other.capacity_}
        , size_{other.size_}
        , data_{new int[other.capacity_]}
{
    *this = other;
}

Int_vector& Int_vector::operator=(const Int_vector& other)
{
    ensure_capacity_(other.size());

    for (size_t i = 0; i < other.size(); ++i) {
        *(data_ + i) = *(other.data_ + i);
    }

    return *this;
}

Int_vector::iterator Int_vector::begin()
{
    return data_;
}

Int_vector::const_iterator Int_vector::begin() const
{
    return data_;
}

Int_vector::iterator Int_vector::end()
{
    return data_ + size_;
}

Int_vector::const_iterator Int_vector::end() const
{
    return data_ + size_;
}

bool operator==(const Int_vector& a, const Int_vector& b)
{
    if (a.size() != b.size()) return false;

    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }

    return true;
}

Int_vector::iterator begin(Int_vector& v)
{
    return v.begin();
}

Int_vector::const_iterator begin(const Int_vector& v)
{
    return v.begin();
}

Int_vector::iterator end(Int_vector& v)
{
    return v.end();
}

Int_vector::const_iterator end(const Int_vector& v)
{
    return v.end();
}
