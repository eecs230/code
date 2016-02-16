#include <Int_vector.h>

constexpr size_t initial_capacity = 10;

Int_vector::Int_vector() : Int_vector(initial_capacity)
{ }

Int_vector::Int_vector(size_t capacity)
        : capacity_{capacity}
        , size_{0}
        , data_{new int[capacity]}
{ }

size_t Int_vector::size() const
{
    return size_;
}

int Int_vector::operator[](size_t index) const
{
    return data_[index];
}

int& Int_vector::operator[](size_t index)
{
    return data_[index];
}
