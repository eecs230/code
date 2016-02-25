#include "String_bst.h"

struct String_bst::Node
{
    std::string           element;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(std::string e, std::shared_ptr<Node> l, std::shared_ptr<Node> r)
            : element{e}, left{l}, right{r} { };
};

String_bst::String_bst() : root_{nullptr} { }


bool String_bst::is_empty() const
{
    return root_ == nullptr;
}

// Helper to compute the size of a tree starting at some node.
size_t size_helper(std::shared_ptr<String_bst::Node> node)
{
    if (node == nullptr) return 0;

    size_t size_left  = size_helper(node->left);
    size_t size_right = size_helper(node->right);

    return size_left + size_right + 1;
}

size_t String_bst::size() const
{
    return size_helper(root_);
}

bool String_bst::contains(const std::string& n) const
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

void String_bst::insert(std::string n)
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

void String_bst::remove(const std::string& n)
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
