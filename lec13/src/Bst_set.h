#pragma once

#include <initializer_list>
#include <iostream>
#include <memory>

template <typename Element>
class Bst_set
{
public:
    Bst_set() = default;
    Bst_set(std::initializer_list<Element>);

    bool empty() const;
    size_t size() const;

    bool contains(const Element&) const;
    void insert(const Element&);
    void remove(const Element&);

    void clear();

private:
    struct Node;
    using link_t = std::shared_ptr<Node>;

    link_t root_ = nullptr;
    size_t size_ = 0;

    template <typename T>
    friend std::ostream& operator<<(std::ostream&, const Bst_set<T>&);
};

template <typename Element>
std::ostream& operator<<(std::ostream&, const Bst_set<Element>&);

//
// IMPLEMENTATION
//

template <typename Element>
struct Bst_set<Element>::Node
{
    Element element;
    link_t  left;
    link_t  right;

    Node(Element e, link_t l, link_t r)
            : element{e}, left{l}, right{r} { }

    static link_t* find(link_t* current, const Element& n)
    {
        while (*current != nullptr) {
            if (n < (*current)->element)
                current = &(*current)->left;
            else if (n > (*current)->element)
                current = &(*current)->right;
            else break;
        }

        return current;
    }

    // Given a pointer to a tree, returns a pointer to the minimum node of
    // the tree.
    static link_t* find_min(link_t* current)
    {
        while ((*current)->left != nullptr)
            current = &(*current)->left;

        return current;
    }

    std::ostream& debug(std::ostream& o)
    {
        o << '(';

        if (left == nullptr) o << '.';
        else left->debug(o);

        o << ' ' << element << ' ';

        if (right == nullptr) o << '.';
        else right->debug(o);

        return o << ')';
    }
};

template <typename Element>
Bst_set<Element>::Bst_set(std::initializer_list<Element> elements)
{
    for (const Element& e : elements) insert(e);
}

template <typename Element>
bool Bst_set<Element>::empty() const
{
    return root_ == nullptr;
}

template <typename Element>
size_t Bst_set<Element>::size() const
{
    return size_;
}

template <typename Element>
bool Bst_set<Element>::contains(const Element& n) const
{
    auto current = root_;

    while (current != nullptr) {
        if (n < current->element)
            current = current->left;
        else if (n > current->element)
            current = current->right;
        else // n == current->element
            return true;
    }

    return false;
}

template <typename Element>
void Bst_set<Element>::insert(const Element& n)
{
    link_t* current = Node::find(&root_, n);

    if (*current == nullptr) {
        *current = std::make_shared<Node>(n, nullptr, nullptr);
        ++size_;
    }
}

template <typename Element>
void Bst_set<Element>::remove(const Element& n)
{
    // First, find the node to remove:
    link_t* current = Node::find(&root_, n);

    // Not found, so just return:
    if (*current == nullptr) return;

    // We're gonna remove it, so decrement the size:
    --size_;

    // No left node, so replace the current node with its right child:
    if ((*current)->left == nullptr)
        *current = (*current)->right;

        // No right node, so replace the current node with its left child:
    else if ((*current)->right == nullptr)
        *current = (*current)->left;

        // Otherwise we're doing this the hard way. We find the next node (in
        // order) after the current node and swap it in place of the current node:
    else {
        // the pointer to the minimum node:
        link_t* min_node = Node::find_min(&(*current)->right);
        // the right child, if any, of the minimum node:
        link_t old_right = (*min_node)->right;

        // Replace current with min_node:
        (*min_node)->left  = (*current)->left;
        (*min_node)->right = (*current)->right;
        *current  = *min_node;

        // Replace min_node with its old right node:
        *min_node = old_right;
    }
}

template <typename Element>
void Bst_set<Element>::clear()
{
    root_ = nullptr;
    size_ = 0;
}

template <typename Element>
std::ostream& operator<<(std::ostream& o, const Bst_set<Element>& set)
{
    return set.root_->debug(o);
}

