// A generic key-to-value dictionary represented as a binary search tree.
#pragma once

#include "Vector.h"

#include <initializer_list>
#include <string>
#include <vector>

namespace dictionary {

class String_int_dict {
public:
    // Default constructor:
    String_int_dict() = default;

    // Construct from a list of pairs:
    String_int_dict(std::initializer_list<std::pair<std::string, int>>);

    // Copy constructor:
    String_int_dict(const String_int_dict&);

    // Copy-assignment operator:
    String_int_dict& operator=(const String_int_dict&);

    // Frees the tree's memory when we're done with it:
    ~String_int_dict();

    bool empty() const;
    size_t size() const;

    // Removes all mappings from the tree
    void clear();

    // Does the dictionary contain the key?
    bool has_key(const std::string&) const;

    // Returns a pointer to the value associated with the given key, or
    // nullptr if not found.
    const int* find(const std::string&) const;
    int* find(const std::string&);

    // Inserts a mapping from the given key to the given value.
    void insert(const std::string&, int);

    // Lookup, but inserts V() (default V) if not found.
    int& operator[](const std::string&);

    std::vector<std::string> get_keys() const;

private:
    struct Node;

    Node* root_  = nullptr;
    size_t size_ = 0;
};

} // end namespace dictionary
