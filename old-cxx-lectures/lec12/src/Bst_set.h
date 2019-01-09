#pragma once

#include <initializer_list>
#include <iostream>
#include <memory>

// Represents a set of `int`s as a binary search tree.
class Bst_set
{
public:
    // Constructs the empty set.
    Bst_set() = default;

    // Constructs the set with the given elements.
    Bst_set(std::initializer_list<int>);

    bool empty() const;
    size_t size() const;

    bool contains(int) const;
    void insert(int);
    void remove(int);

    void clear();

private:
    // Pimpl (pointer-to-implementation) idiom here. The tree will be
    // represented as a shared pointer to its root node, but the Node struct
    // itself is defined in the implementation (.cpp) file, since it doesn't
    // need to be visible to clients.
    struct Node;
    using link_t = std::shared_ptr<Node>;

    link_t root_ = nullptr;
    size_t size_ = 0;
    // Invariant:
    //  - `size_` is the number of nodes in the tree `root_`

    // A friend declaration means that the given function (or class) can see
    // this class's private members. In this case, we make operator<< a
    // friend so it can see `root_` in order to print it.
    friend std::ostream& operator<<(std::ostream&, const Bst_set&);
};

// Prints the BST in a manner suitable for debugging.
std::ostream& operator<<(std::ostream&, const Bst_set&);
