#pragma once

#include <initializer_list>
#include <iostream>
#include <memory>
#include <tuple>

template <typename K, typename V>
class Bst_map
{
public:
    Bst_map() = default;
    Bst_map(std::initializer_list<std::tuple<K, V>>);

    bool is_empty() const;
    size_t size() const;

    bool contains_key(const K&) const;
    const V* find(const K&) const;
    V* find(const K&);
    void insert(K, V);
    void remove(const K&);

    std::ostream& debug(std::ostream&);

private:
    struct Node;
    using link_t = std::shared_ptr<Node>;

    link_t root_ = nullptr;
    size_t size_ = 0;
};

template <typename K, typename V>
struct Bst_map<K, V>::Node
{
    K      key;
    V      val;
    link_t left;
    link_t right;

    Node(K k, V v, link_t l, link_t r)
            : key{k}, val{v}, left{l}, right{r}
    { }

    static link_t* find(link_t* current, const K& k)
    {
        while (*current != nullptr) {
            if (k < (*current)->key)
                current = &(*current)->left;
            else if (k > (*current)->key)
                current = &(*current)->right;
            else break;
        }

        return current;
    }

    static const link_t* find(const link_t* current, const K& k)
    {
        while (*current != nullptr) {
            if (k < (*current)->key)
                current = &(*current)->left;
            else if (k > (*current)->key)
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

        o << ' ' << key << ':' << val << ' ';

        if (right == nullptr) o << '.';
        else right->debug(o);

        return o << ')';
    }
};

template <typename K, typename V>
bool Bst_map<K, V>::is_empty() const
{
    return root_ == nullptr;
}

template <typename K, typename V>
size_t Bst_map<K, V>::size() const
{
    return size_;
}

template <typename K, typename V>
bool Bst_map<K, V>::contains_key(const K& k) const
{
    auto current = root_;

    while (current != nullptr) {
        if (k < current->key)
            current = current->left;
        else if (k > current->key)
            current = current->right;
        else // k == current->key
            return true;
    }

    return false;
}

template <typename K, typename V>
const V* Bst_map<K, V>::find(const K& k) const
{
    auto current = Node::find(&root_, k);
    if (*current == nullptr) return nullptr;
    else return &(*current)->val;
}

template <typename K, typename V>
V* Bst_map<K, V>::find(const K& k)
{
    auto current = Node::find(&root_, k);
    if (*current == nullptr) return nullptr;
    else return &(*current)->val;
}

template <typename K, typename V>
void Bst_map<K, V>::insert(K k, V v)
{
    link_t* current = Node::find(&root_, k);

    if (*current == nullptr) {
        *current = std::make_shared<Node>(k, v, nullptr, nullptr);
        ++size_;
    }
}

template <typename K, typename V>
void Bst_map<K, V>::remove(const K& k)
{
    // First, find the node to remove:
    link_t* current = Node::find(&root_, k);

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

template <typename K, typename V>
std::ostream& Bst_map<K, V>::debug(std::ostream& o)
{
    return root_->debug(o);
}

