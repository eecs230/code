#include "String_bst_set.h"

struct String_bst_set::Node
{
    std::string element;
    link_t      left;
    link_t      right;

    Node(const std::string& e, link_t l, link_t r)
            : element{e}, left{l}, right{r} { }

    static link_t* find(link_t* current, const std::string& n)
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

String_bst_set::String_bst_set(std::initializer_list<std::string> elements)
{
    for (const std::string& e : elements) insert(e);
}

bool String_bst_set::is_empty() const
{
    return root_ == nullptr;
}

size_t String_bst_set::size() const
{
    return size_;
}

bool String_bst_set::contains(const std::string& n) const
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

void String_bst_set::insert(const std::string& n)
{
    link_t* current = Node::find(&root_, n);

    if (*current == nullptr) {
        *current = std::make_shared<Node>(n, nullptr, nullptr);
        ++size_;
    }
}

void String_bst_set::remove(const std::string& n)
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

std::ostream& String_bst_set::debug(std::ostream& o)
{
    return root_->debug(o);
}


