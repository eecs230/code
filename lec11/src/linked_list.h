#pragma once

#include <memory>
#include <string>

namespace linked_list {

// A linked list represented as a shared pointer to a List_node, which
// contains two data members, one element and one shared pointer to the next
// List_node.
struct List_node
{
    // A link is a shared pointer to a List_node.
    using link_t = std::shared_ptr<List_node>;

    // Constructs a list node from its element and rest pointer.
    List_node(const std::string& f, link_t r);

    // For iterating over lists (defined below):
    class iterator;

    std::string first;
    link_t      rest;
};

// A type synonym: a List *is* a shared pointer to a list node.
using List = List_node::link_t;

/////
///// FREE FUNCTIONS FOR `List`.
/////

// Allocates a new node on the free store, with the given value and rest
// pointer.
List cons(std::string first, List rest);

// Gets the first element of a list.
// PRECONDITION: the List is not nullptr
std::string& first(List);

// Gets the rest pointer of a list.
// PRECONDITION: the List is not nullptr
List& rest(List);

// Computes the length of a list (the number of nodes).
size_t length(List);

// Appends two lists together to get a list with all the elements of both.
List append(List, List);

// Constructs the reverse of a list.
List reverse(List);

// Structural equality for lists determines whether two lists have the same
// elements. (operator== does pointer identity.)
bool equals(List, List);

/////
///// ITERATOR STUFF
/////

class List_node::iterator
{
public:
    iterator& operator++();
    iterator operator++(int);

    const std::string& operator*() const;
    const std::string* operator->() const;

private:
    iterator(const List_node*);

    const List_node* ptr_;

    friend class List_node;
    friend bool operator==(iterator, iterator);
    friend iterator begin(List);
    friend iterator end(List);
};

// Returns an iterator to the beginning of the list.
List_node::iterator begin(List);

// Returns an iterator to the end of the list.
List_node::iterator end(List);

bool operator==(List_node::iterator, List_node::iterator);
bool operator!=(List_node::iterator, List_node::iterator);

} // end cons_list
