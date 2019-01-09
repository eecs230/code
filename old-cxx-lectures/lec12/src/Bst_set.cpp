#include "Bst_set.h"

// A tree will be represented as a linked structure containing nodes. Each
// node contains one set element, as well as links to (optional) left and
// right subtrees.
struct Bst_set::Node
{
    int    element;
    link_t left;
    link_t right;
    // Invariants:
    //  - all the elements of `left` < `element`
    //  - all the elements of `right` > `element`

    // Constructs a node with the given element and left and right subtrees.
    Node(int, link_t, link_t);

    // Finds the pointer to the node with the given value `n`, or the pointer
    // to where that node should exist if it doesn't.
    static link_t* find(link_t* current, int n);

    // Given a pointer to a tree, returns a pointer to the minimum node of
    // the tree.
    // PRECONDITION: parameter is non-null
    static link_t* find_min(link_t*);

    // Prints out a representation of the tree rooted at this node suitable
    // for debugging.
    std::ostream& debug(std::ostream&) const;
};

Bst_set::Node::Node(int e, link_t l, link_t r)
        : element(e), left(l), right(r)
{ }

Bst_set::link_t* Bst_set::Node::find(link_t* current, int n)
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

Bst_set::link_t* Bst_set::Node::find_min(link_t* current)
{
    while ((*current)->left != nullptr)
        current = &(*current)->left;

    return current;
}

std::ostream& Bst_set::Node::debug(std::ostream& o) const
{
    o << '(';

    if (left == nullptr) o << '.';
    else left->debug(o);

    o << ' ' << element << ' ';

    if (right == nullptr) o << '.';
    else right->debug(o);

    return o << ')';
}

Bst_set::Bst_set(std::initializer_list<int> elements)
{
    for (int e : elements) insert(e);
}

bool Bst_set::empty() const
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

    // This is the standard algorithm for searching a binary search tree.
    // Start at the root and look to the left or right, depending on the
    // ordering invariant, until either reaching the element searched for or
    // the bottom of the tree.
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
    // Find where the given element `n` is or should be:
    link_t* current = Node::find(&root_, n);

    // If the place where it "should be" is null, we make a new node and hang
    // it there:
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

        // Replace current node with min_node:
        (*min_node)->left  = (*current)->left;
        (*min_node)->right = (*current)->right;
        *current  = *min_node;

        // Replace min_node with its right child:
        *min_node = old_right;
    }
}

void Bst_set::clear()
{
    root_ = nullptr;
    size_ = 0;
}

std::ostream& operator<<(std::ostream& o, const Bst_set& set)
{
    return set.root_->debug(o);
}

