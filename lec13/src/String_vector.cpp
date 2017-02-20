#include "String_vector.h"

#include <stdexcept>

using namespace std;

String_vector::String_vector(size_t initial_capacity)
        : capacity_(initial_capacity)
        , size_(0)
        , data_(new string[initial_capacity])
{ }

String_vector::String_vector()
        : String_vector(default_initial_capacity)
{ }

String_vector::String_vector(initializer_list<string> elements)
        : String_vector(elements.size())
{
    for (const string& z : elements) push_back(z);
}

String_vector::String_vector(const String_vector& other)
        : String_vector(other.size())
{
    for (const string& z : other) push_back(z);
}

String_vector& String_vector::operator=(const String_vector& other)
{
    clear();
    ensure_capacity_(other.size());
    for (const string& z : other) push_back(z);

    return *this;
}

String_vector::~String_vector()
{
    delete[] data_;
}

bool String_vector::empty() const
{
    return size_ == 0;
}

size_t String_vector::size() const
{
    return size_;
}

void String_vector::push_back(const string& i)
{
    ensure_capacity_(size_ + 1);
    *(data_ + size_) = i;
    ++size_;
}

void String_vector::pop_back()
{
    --size_;
}

void String_vector::clear()
{
    size_ = 0;
}

const string& String_vector::front() const
{
    return *data_;
}

string& String_vector::front()
{
    return *data_;
}

const string& String_vector::back() const
{
    return *(data_ + size_ - 1);
}

string& String_vector::back()
{
    return *(data_ + size_ - 1);
}

const string& String_vector::operator[](size_t n) const
{
    return *(data_ + n);
}

string& String_vector::operator[](size_t n)
{
    return *(data_ + n);
}

const string& String_vector::at(size_t n) const
{
    check_index_(n);
    return *(data_ + n);
}

string& String_vector::at(size_t n)
{
    check_index_(n);
    return *(data_ + n);
}

String_vector::iterator String_vector::begin()
{
    return data_;
}

String_vector::const_iterator String_vector::begin() const
{
    return data_;
}

String_vector::const_iterator String_vector::cbegin() const
{
    return data_;
}

String_vector::iterator String_vector::end()
{
    return data_ + size_;
}

String_vector::const_iterator String_vector::end() const
{
    return data_ + size_;
}

String_vector::const_iterator String_vector::cend() const
{
    return data_ + size_;
}

String_vector::reverse_iterator String_vector::rbegin()
{
    return reverse_iterator(end());
}

String_vector::const_reverse_iterator String_vector::rbegin() const
{
    return const_reverse_iterator(end());
}

String_vector::const_reverse_iterator String_vector::crbegin() const
{
    return const_reverse_iterator(end());
}

String_vector::reverse_iterator String_vector::rend()
{
    return reverse_iterator(begin());
}

String_vector::const_reverse_iterator String_vector::rend() const
{
    return const_reverse_iterator(begin());
}

String_vector::const_reverse_iterator String_vector::crend() const
{
    return const_reverse_iterator(begin());
}

void String_vector::check_index_(size_t index) const
{
    if (index >= size_)
        throw std::range_error("String_vector: index out of bounds");
}

void String_vector::ensure_capacity_(size_t req_capacity)
{
    if (req_capacity <= capacity_) return;

    size_t new_capacity = max(req_capacity, 2 * capacity_);
    string* new_data    = new string[new_capacity];

    for (size_t i = 0; i < size_; ++i) {
        *(new_data + i) = *(data_ + i);
    }

    delete[] data_;

    data_     = new_data;
    capacity_ = new_capacity;
}

bool operator==(const String_vector& a, const String_vector& b)
{
    if (a.size() != b.size()) return false;

    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }

    return true;
}

bool operator!=(const String_vector& a, const String_vector& b)
{
    return !(a == b);
}

bool operator<(const String_vector& a, const String_vector& b)
{
    size_t limit = min(a.size(), b.size());

    for (size_t i = 0; i < limit; ++i) {
        if (a[i] < b[i]) return true;
        if (b[i] < a[i]) return false;
    }

    return a.size() < b.size();
}

bool operator<=(const String_vector& a, const String_vector& b)
{
    return !(b < a);
}

bool operator> (const String_vector& a, const String_vector& b)
{
    return b < a;
}

bool operator>=(const String_vector& a, const String_vector& b)
{
    return !(a < b);
}
