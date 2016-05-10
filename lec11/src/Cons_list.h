#pragma once

#include <memory>
#include <string>

namespace cons_list {

class Cons_list_node {
public:
    using Cons_list = std::shared_ptr<Cons_list_node>;

    Cons_list_node(std::string first, Cons_list rest);

    const std::string& first() const;
    Cons_list rest() const;

private:
    std::string first_;
    Cons_list rest_;

public:
    class iterator {
    public:
        iterator& operator++();
        iterator operator++(int);
        const std::string& operator*() const;

        friend class Cons_list_node;
        friend bool operator==(iterator, iterator);

    private:
        iterator(const Cons_list_node*);
        const Cons_list_node* ptr_;
    };

    iterator begin() const;
    iterator end() const;
};

using Cons_list = Cons_list_node::Cons_list;

bool operator==(Cons_list_node::iterator, Cons_list_node::iterator);
bool operator!=(Cons_list_node::iterator, Cons_list_node::iterator);

Cons_list cons(std::string first, Cons_list rest);
const std::string& first(Cons_list);
Cons_list rest(Cons_list);

Cons_list_node::iterator begin(Cons_list);
Cons_list_node::iterator end(Cons_list);

size_t length(Cons_list);

Cons_list append(Cons_list, Cons_list);
Cons_list reverse(Cons_list);

bool operator==(Cons_list, Cons_list);

} // end cons_list
