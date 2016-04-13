#pragma once

#include <memory>

template <typename Element>
class Bst
{
public:
    Bst() : root_{nullptr}
    { }

    bool is_empty() const
    { return root_ == nullptr; }

    size_t size() const;

    bool contains(const Element&) const;
    void insert(Element);
    void remove(const Element&);

private:
    struct Node;
    std::shared_ptr<Node> root_;

    static size_t size_helper(std::shared_ptr<Node>);
};

template <typename Element>
struct Bst<Element>::Node
{
    Element element;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(Element e, std::shared_ptr<Node> l, std::shared_ptr<Node> r)
            : element{e}, left{l}, right{r} { };
};

// Helper to compute the size of a tree starting at some node.
template <typename Element>
size_t Bst<Element>::size_helper(std::shared_ptr<Node> node)
{
    if (node == nullptr) return 0;

    size_t size_left  = size_helper(node->left);
    size_t size_right = size_helper(node->right);

    return size_left + size_right + 1;
}

template <typename Element>
size_t Bst<Element>::size() const
{
    return size_helper(root_);
}

template <typename Element>
bool Bst<Element>::contains(const Element& n) const
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

template <typename Element>
void Bst<Element>::insert(Element n)
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

template <typename Element>
void Bst<Element>::remove(const Element& n)
{
    std::shared_ptr<Node>* current = &root_;

    while (*current != nullptr) {
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

            return;
        }

        if (n < (*current)->element)
            current = &(*current)->left;
        else // n > current->element
            current = &(*current)->right;
    }
}
