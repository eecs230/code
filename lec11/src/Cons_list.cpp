#include "Cons_list.h"

namespace list {

String_list_node::String_list_node(std::string first, String_list rest)
    : first_{first}, rest_{rest}
{ }

const std::string& String_list_node::first() const
{
    return first_;
}

String_list String_list_node::rest() const
{
    return rest_;
}

using iterator = String_list_node::iterator;

iterator String_list_node::begin() const
{
    return iterator{this};
}

iterator String_list_node::end() const
{
    return iterator{nullptr};
}

iterator::iterator(const String_list_node* ptr)
    : ptr_{ptr}
{ }

iterator& iterator::operator++()
{
    ptr_ = &*ptr_->rest();
    return *this;
}

iterator iterator::operator++(int)
{
    iterator old = *this;
    ++(*this);
    return old;
}

const std::string& iterator::operator*() const
{
    return ptr_->first();
}

bool operator==(iterator a, iterator b)
{
    return a.ptr_ == b.ptr_;
}

bool operator!=(iterator a, iterator b)
{
    return !(a == b);
}

String_list cons(std::string first, String_list rest)
{
    return std::make_shared<String_list_node>(first, rest);
}

const std::string& first(String_list lst)
{
    return (*lst).first();
}

String_list rest(String_list lst)
{
    return lst->rest();
}

iterator begin(String_list lst)
{
    return lst->begin();
}

iterator end(String_list lst)
{
    return lst->end();
}

size_t length(String_list lst)
{
    size_t result = 0;

    while (lst != nullptr) {
        ++result;
        lst = lst->rest();
    }

    return result;
}

String_list append(String_list front, String_list back)
{
    if (front == nullptr) return back;
    else return cons(front->first(), append(front->rest(), back));
}

bool operator==(Cons_list a, Cons_list b)
{
    if (a == nullptr) return b == nullptr;
    else if (b == nullptr) return false;

    return a->first() == b->first() && a->rest() == b->rest();
}

String_list reverse(String_list lst)
{
    String_list result = nullptr;

    while (lst != nullptr) {
        result = cons(lst->first(), result);
        lst    = lst->rest();
    }

    return result;
}

} // end namespace cons_list
