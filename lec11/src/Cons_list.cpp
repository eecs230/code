#include "Cons_list.h"

namespace linked_list {

List_node::List_node(std::string first, link_t rest)
    : first_{first}, rest_{rest}
{ }

const std::string& List_node::first() const
{
    return first_;
}

link_t List_node::rest() const
{
    return rest_;
}

using iterator = List_node::iterator;

iterator List_node::begin() const
{
    return iterator{this};
}

iterator List_node::end() const
{
    return iterator{nullptr};
}

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

bool operator==(iterator a, iterator b)
{
    return a.ptr_ == b.ptr_;
}

bool operator!=(iterator a, iterator b)
{
    return !(a == b);
}

List cons(std::string first, List rest)
{
    return std::make_shared<List_node>(first, rest);
}

const std::string& first(List lst)
{
    return (*lst).first();
}

List rest(List lst)
{
    return lst->rest();
}

iterator begin(List lst)
{
    return lst->begin();
}

iterator end(List lst)
{
    return lst->end();
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

bool operator==(Cons_list a, Cons_list b)
{
    if (a == nullptr) return b == nullptr;
    else if (b == nullptr) return false;

    return a->first() == b->first() && a->rest() == b->rest();
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

} // end namespace cons_list
