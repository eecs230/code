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
    return lst->first_;
}

Cons_list rest(Cons_list lst)
{
    return lst->rest_;
}

} // end namespace cons_list
