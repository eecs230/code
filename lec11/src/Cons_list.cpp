#include "Cons_list.h"

namespace cons_list {

Cons_list_node::Cons_list_node(std::string first, Cons_list rest)
    : first_{first}, rest_{rest}
{ }

Cons_list cons(std::string first, Cons_list rest)
{
    return std::make_shared<Cons_list_node>(first, rest);
}


const std::string& first(Cons_list lst)
{
    return (*lst).first_;
}

Cons_list rest(Cons_list lst)
{
    // *lst.rest_ means *(lst.rest_)
    // lst->rest  means (*lst).rest_

    return lst->rest_;
}

size_t length(Cons_list lst)
{
    size_t result = 0;

    while (lst != nullptr) {
        ++result;
        lst = rest(lst);
    }

    return result;
}

Cons_list append(Cons_list front, Cons_list back)
{
    if (front == nullptr) return back;
    else return cons(first(front), append(rest(front), back));
}

bool operator==(Cons_list a, Cons_list b)
{
    if (a == nullptr) return b == nullptr;
    else if (b == nullptr) return false;

    return first(a) == first(b) && rest(a) == rest(b);
}

Cons_list reverse(Cons_list lst)
{
    Cons_list result = nullptr;

    while (lst != nullptr) {
        result = cons(first(lst), result);
        lst    = rest(lst);
    }

    return result;
}

} // end namespace cons_list
