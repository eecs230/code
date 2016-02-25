#include "Int_bst.h"

struct Int_bst::Node
{
    int                   element;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(int e, std::shared_ptr<Node> l, std::shared_ptr<Node> r)
            : element{e}, left{l}, right{r} { };
};

Int_bst::Int_bst() : root_{nullptr} { }


bool Int_bst::is_empty() const
{
    return root_ == nullptr;
}

// Helper to compute the size of a tree starting at some node.
size_t size_helper(std::shared_ptr<Int_bst::Node> node)
{
    if (node == nullptr) return 0;

    size_t size_left  = size_helper(node->left);
    size_t size_right = size_helper(node->right);

    return size_left + size_right + 1;
}

size_t Int_bst::size() const
{
    return size_helper(root_);
}

bool Int_bst::contains(int n) const
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

void Int_bst::insert(int n)
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

void Int_bst::remove(int n)
{
    std::shared_ptr<Node>* current = &root_;

    while (current != nullptr) {
        if (n == (*current)->element) {
            if ((*current)->right == nullptr) {
                *current = (*current)->left;
            } else {
                std::shared_ptr<Node>* succ = &(*current)->right;
                while ((*succ)->left != nullptr)
                    succ = &(*succ)->left;

                std::shared_ptr<Node> temp = *succ;
                *succ = (*succ)->right;
                temp->left = (*current)->left;
                temp->right = (*current)->right;
                *current = temp;
            }
        }

        if (n < (*current)->element)
            current = &(*current)->left;
        else // n > current->element
            current = &(*current)->right;
    }
}
