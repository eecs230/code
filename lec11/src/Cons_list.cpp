#include "Cons_list.h"

namespace cons_list {

Cons_list_node::Cons_list_node(std::string first, Cons_list rest)
    : first_{first}, rest_{rest}
{ }

const std::string& Cons_list_node::first() const
{
    return first_;
}

Cons_list Cons_list_node::rest() const
{
    return rest_;
}

using iterator = Cons_list_node::iterator;

iterator Cons_list_node::begin() const
{
    return iterator{this};
}

iterator Cons_list_node::end() const
{
    return iterator{nullptr};
}

iterator::iterator(const Cons_list_node* ptr)
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

Cons_list cons(std::string first, Cons_list rest)
{
    return std::make_shared<Cons_list_node>(first, rest);
}

const std::string& first(Cons_list lst)
{
    return (*lst).first();
}

Cons_list rest(Cons_list lst)
{
    return lst->rest();
}

iterator begin(Cons_list lst)
{
    return lst->begin();
}

iterator end(Cons_list lst)
{
    return lst->end();
}

size_t length(Cons_list lst)
{
    size_t result = 0;

    while (lst != nullptr) {
        ++result;
        lst = lst->rest();
    }

    return result;
}

Cons_list append(Cons_list front, Cons_list back)
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

Cons_list reverse(Cons_list lst)
{
    Cons_list result = nullptr;

    while (lst != nullptr) {
        result = cons(lst->first(), result);
        lst    = lst->rest();
    }

    return result;
}

} // end namespace cons_list
