#pragma once

#include <memory>
#include <string>

namespace cons_list
{

struct Cons_list_node
{
public:
    using Cons_list = std::shared_ptr<Cons_list_node>;

    friend Cons_list cons(std::string first, Cons_list rest);
    friend const std::string& first(Cons_list);
    friend Cons_list rest(Cons_list);

    Cons_list_node(std::string, Cons_list);

private:
    std::string first_;
    Cons_list rest_;
};

using Cons_list = Cons_list_node::Cons_list;

} // end namespace cons_list
