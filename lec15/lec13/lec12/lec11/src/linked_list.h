#pragma once

#include <memory>
#include <string>

namespace linked_list {

class List_node
{
public:
    using link_t = std::shared_ptr<List_node>;

    List_node(std::string first, link_t rest);

    const std::string& first() const;
    link_t rest() const;

private:
    std::string first_;
    link_t      rest_;

public:
    class iterator
    {
    public:
        iterator& operator++();
        iterator operator++(int);

        const std::string& operator*() const;

        friend class List_node;
        friend bool operator==(iterator, iterator);

    private:
        iterator(const List_node*);

        const List_node* ptr_;
    };

    iterator begin() const;
    iterator end() const;
};

using List = List_node::link_t;

List cons(std::string first, List rest);
const std::string& first(List);
List rest(List);

size_t length(List);

List append(List, List);
List reverse(List);

bool operator==(List, List);

List_node::iterator begin(List);
List_node::iterator end(List);

bool operator==(List_node::iterator, List_node::iterator);
bool operator!=(List_node::iterator, List_node::iterator);

} // end cons_list
