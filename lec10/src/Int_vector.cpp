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

Int_vector::Int_vector(std::initializer_list<int> elements)
        : Int_vector(elements.size())
{
    for (int z : elements) push_back(z);
}

Int_vector::Int_vector(const Int_vector& other)
        : Int_vector(other.size())
{
    for (int z : other) push_back(z);
}

Int_vector& Int_vector::operator=(const Int_vector& other)
{
    clear();
    ensure_capacity_(other.size());
    for (int z : other) push_back(z);

    return *this;
}

Int_vector::~Int_vector()
{
    delete[] data_;
}

bool Int_vector::empty() const
{
    return size_ == 0;
}

size_t Int_vector::size() const
{

}

void Int_vector::push_back(int i)
{
    ensure_capacity_(size_ + 1);
    *(data_ + size_) = i;
    ++size_;
}

void Int_vector::pop_back()
{
    --size_;
}

void Int_vector::clear()
{
    size_ = 0;
}

int Int_vector::front() const
{
    return *data_;
}

int& Int_vector::front()
{
    return *data_;
}

int Int_vector::back() const
{
    return *(data_ + size_ - 1);
}

int& Int_vector::back()
{
    return *(data_ + size_ - 1);
}

int Int_vector::operator[](size_t n) const
{
    return *(data_ + n);
}

int& Int_vector::operator[](size_t n)
{
    return *(data_ + n);
}

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

Int_vector::iterator Int_vector::begin()
{
    return data_;
}

Int_vector::const_iterator Int_vector::begin() const
{
    return data_;
}

Int_vector::const_iterator Int_vector::cbegin() const
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

Int_vector::const_iterator Int_vector::cend() const
{
    return data_ + size_;
}

Int_vector::reverse_iterator Int_vector::rbegin()
{
    return reverse_iterator(end());
}

Int_vector::const_reverse_iterator Int_vector::rbegin() const
{
    return const_reverse_iterator(end());
}

Int_vector::const_reverse_iterator Int_vector::crbegin() const
{
    return const_reverse_iterator(end());
}

Int_vector::reverse_iterator Int_vector::rend()
{
    return reverse_iterator(begin());
}

Int_vector::const_reverse_iterator Int_vector::rend() const
{
    return const_reverse_iterator(begin());
}

Int_vector::const_reverse_iterator Int_vector::crend() const
{
    return const_reverse_iterator(begin());
}

void Int_vector::check_index_(size_t index) const
{
    if (index >= size_) throw range_error{};
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

bool operator==(const Int_vector& a, const Int_vector& b)
{
    if (a.size() != b.size()) return false;

    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }

    return true;
}

bool operator!=(const Int_vector& a, const Int_vector& b)
{
    return !(a == b);
}

bool operator<(const Int_vector& a, const Int_vector& b)
{
    size_t limit = std::min(a.size(), b.size());

    for (size_t i = 0; i < limit; ++i) {
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
    }

    return a.size() < b.size();
}

bool operator<=(const Int_vector& a, const Int_vector& b)
{
    return !(b < a);
}

bool operator> (const Int_vector& a, const Int_vector& b)
{
    return b < a;
}

bool operator>=(const Int_vector& a, const Int_vector& b)
{
    return !(a < b);
}
