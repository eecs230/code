#include "Bst.h"

struct Bst::Node
{
    int                   element;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(int e, std::shared_ptr<Node> l, std::shared_ptr<Node> r)
            : element{e}, left{l}, right{r} { };
};

Bst::Bst() : root_{nullptr} { }


bool Bst::is_empty() const
{
    return root_ == nullptr;
}

// Helper to compute the size of a tree starting at some node.
size_t size_helper(std::shared_ptr<Bst::Node> node)
{
    if (node == nullptr) return 0;

    size_t size_left  = size_helper(node->left);
    size_t size_right = size_helper(node->right);

    return size_left + size_right + 1;
}

size_t Bst::size() const
{
    return size_helper(root_);
}

bool Bst::contains(int n) const
{
    std::shared_ptr<Node> current = root_;

    while (current != nullptr) {
        if (n == current->element)
            return true;

        if (n < current->element)
            current = current->left;
        else // n > current->element
            current = current->right;
    }

    return false;
}

void Bst::insert(int n)
{
    std::shared_ptr<Node>* current = &root_;

    while (*current != nullptr) {
        if (n == (*current)->element)
            return;

        if (n < (*current)->element)
            current = &(*current)->left;
        else // n > current->element
            current = &(*current)->right;
    }

    std::shared_ptr<Node> new_node = std::make_shared<Node>(n, nullptr,
                                                            nullptr);
    *current = new_node;
}
