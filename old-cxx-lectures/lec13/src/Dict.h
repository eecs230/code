// A generic key-to-value dictionary represented as a binary search tree.
#pragma once

#include "Vector.h"

#include <initializer_list>

namespace dictionary {

template <typename K, typename V>
class Dict {
public:
    // Default constructor:
    Dict() = default;

    // Construct from a list of pairs:
    Dict(std::initializer_list<std::pair<K, V>>);

    // Copy constructor:
    Dict(const Dict&);

    // Copy-assignment operator:
    Dict& operator=(const Dict&);

    // Frees the tree's memory when we're done with it:
    ~Dict();

    bool empty() const;
    size_t size() const;

    // Removes all mappings from the tree
    void clear();

    // Does the dictionary contain the key?
    bool has_key(const K&) const;

    // Returns a pointer to the value associated with the given key, or
    // nullptr if not found.
    const V* find(const K&) const;
    V* find(const K&);

    // Inserts a mapping from the given key to the given value.
    void insert(const K&, const V&);

    // Lookup, but inserts V() (default V) if not found.
    V& operator[](const K&);

    Vector<K> get_keys() const;

private:
    struct Node;

    Node* root_  = nullptr;
    size_t size_ = 0;
};

///
/// IMPLEMENTATION
///

template <typename K, typename V>
struct Dict<K, V>::Node
{
    K key;
    V value;
    Node* left;
    Node* right;

    Node(const K& k, const V& v, Node* l, Node* r)
            : key(k), value(v), left(l), right(r)
    { }

    static void deep_delete(Node*);
    static Node* deep_clone(const Node*);

    static void get_keys_helper(Node*, Vector<K>&);

    static Node* find(Node*, const K&);
    static Node** find_mut(Node**, const K&);
};

template <typename K, typename V>
Dict<K, V>::Dict(std::initializer_list<std::pair<K, V>> mappings)
{
    for (const std::pair<K, V>& each : mappings)
        insert(each.first, each.second);
}

template <typename K, typename V>
Dict<K, V>::Dict(const Dict& that)
        : size_(that.size_),
          root_(Node::deep_clone(that.root_))
{ }

template <typename K, typename V>
Dict<K, V>& Dict<K, V>::operator=(const Dict& that)
{
    Node::deep_delete(root_);
    size_ = that.size_;
    root_ = Node::deep_clone(that.root_);

    return *this;
}

template <typename K, typename V>
Dict<K, V>::~Dict()
{
    Node::deep_delete(root_);
}

template <typename K, typename V>
bool Dict<K, V>::empty() const {
    return root_ == nullptr;
}

template <typename K, typename V>
size_t Dict<K, V>::size() const {
    return size_;
}

template <typename K, typename V>
void Dict<K, V>::clear()
{
    Node::deep_delete(root_);
    root_ = nullptr;
    size_ = 0;
}

template <typename K, typename V>
bool Dict<K, V>::has_key(const K& key) const
{
    return Node::find(root_, key) != nullptr;
}

template <typename K, typename V>
const V* Dict<K, V>::find(const K& key) const
{
    Node* node = Node::find(root_, key);
    if (node == nullptr) return nullptr;
    else return &node->value;
}

template <typename K, typename V>
V* Dict<K, V>::find(const K& key)
{
    Node* node = Node::find(root_, key);
    if (node == nullptr) return nullptr;
    else return &node->value;
}

template <typename K, typename V>
void Dict<K, V>::insert(const K& key, const V&value)
{
    Node** node = Node::find_mut(&root_, key);

    if (*node == nullptr) {
        *node = new Node(key, value, nullptr, nullptr);
        ++size_;
    } else {
        (*node)->value = value;
    }
}

template <typename K, typename V>
V& Dict<K, V>::operator[](const K& key)
{
    Node** node = Node::find_mut(&root_, key);

    if (*node == nullptr) {
        *node = new Node(key, V(), nullptr, nullptr);
        ++size_;
    }

    return (*node)->value;
}

template <typename K, typename V>
void Dict<K, V>::Node::get_keys_helper(Node* node, Vector<K>& out)
{
    if (node != nullptr) {
        Node::get_keys_helper(node->left, out);
        out.push_back(node->key);
        Node::get_keys_helper(node->right, out);
    }
}

template <typename K, typename V>
Vector<K> Dict<K, V>::get_keys() const
{
    Vector<K> result;
    Node::get_keys_helper(root_, result);
    return result;
}

template <typename K, typename V>
void Dict<K, V>::Node::deep_delete(Node* node)
{
    if (node) {
        Node::deep_delete(node->left);
        Node::deep_delete(node->right);
        delete node;
    }
}

template <typename K, typename V>
auto Dict<K, V>::Node::deep_clone(const Node* node) -> Node*
{
    if (node)
        return new Node(node->key, node->value,
                        Node::deep_clone(node->left),
                        Node::deep_clone(node->right));
    else
        return nullptr;
}

template <typename K, typename V>
auto Dict<K, V>::Node::find(Node* node, const K& key) -> Node*
{
    while (node != nullptr) {
        if (key < node->key)
            node = node->left;
        else if (key > node->key)
            node = node->right;
        else
            break;
    }

    return node;
}

template <typename K, typename V>
auto Dict<K, V>::Node::find_mut(Node** node, const K& key) -> Node**
{
    while (*node != nullptr) {
        if (key < (*node)->key)
            node = &(*node)->left;
        else if (key > (*node)->key)
            node = &(*node)->right;
        else
            break;
    }

    return node;
}

} // end namespace dictionary
