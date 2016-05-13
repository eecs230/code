#include "Int_bst_set.h"

struct Bst_set::Node
{
    int    element;
    link_t left;
    link_t right;

    Node(int e, link_t l, link_t r)
            : element{e}, left{l}, right{r} { }

    static link_t* find(link_t* current, int n)
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

Bst_set::Bst_set(std::initializer_list<int> elements)
{
    for (int e : elements) insert(e);
}

bool Bst_set::is_empty() const
{
    return root_ == nullptr;
}

size_t Bst_set::size() const
{
    return size_;
}

bool Bst_set::contains(int n) const
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

void Bst_set::insert(int n)
{
    link_t* current = Node::find(&root_, n);

    if (*current == nullptr) {
        *current = std::make_shared<Node>(n, nullptr, nullptr);
        ++size_;
    }
}

void Bst_set::remove(int n)
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

        (*min_node)->left  = (*current)->left;
        (*min_node)->right = (*current)->right;
        *current  = *min_node;
        *min_node = old_right;
    }
}

std::ostream& Bst_set::debug(std::ostream& o)
{
    return root_->debug(o);
}


