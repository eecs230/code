#include "linked_list.h"

namespace linked_list {

List_node::List_node(const std::string& first, link_t rest)
    : first_{first}, rest_{rest}
{ }

const std::string& List_node::first() const
{
    return first_;
}

List List_node::rest() const
{
    return rest_;
}

List cons(std::string first, List rest)
{
    return std::make_shared<List_node>(first, rest);
}

const std::string& first(List lst)
{
    return lst->first();
}

List rest(List lst)
{
    return lst->rest();
}

size_t length(List lst)
{
    size_t result = 0;

    while (lst != nullptr) {
        ++result;
        lst = lst->rest();
    }

    return result;
}

List append(List front, List back)
{
    if (front == nullptr) return back;
    else return cons(front->first(), append(front->rest(), back));
}

List reverse(List lst)
{
    List result = nullptr;

    while (lst != nullptr) {
        result = cons(lst->first(), result);
        lst    = lst->rest();
    }

    return result;
}

bool equals(List a, List b)
{
    if (a == nullptr) return b == nullptr;
    if (b == nullptr) return false;

    return first(a) == first(b) && equals(rest(a), rest(b));
}

using iterator = List_node::iterator;

iterator::iterator(const List_node* ptr)
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

const std::string* iterator::operator->() const
{
    return &operator*();
}

iterator begin(List lst)
{
    return iterator(&*lst);
}

iterator end(List lst)
{
    return iterator(nullptr);
}

bool operator==(iterator a, iterator b)
{
    return a.ptr_ == b.ptr_;
}

bool operator!=(iterator a, iterator b)
{
    return !(a == b);
}

} // end namespace cons_list
