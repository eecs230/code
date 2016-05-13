#pragma once

#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>

class String_bst_set
{
public:
    String_bst_set() = default;
    String_bst_set(std::initializer_list<std::string>);

    bool is_empty() const;
    size_t size() const;

    bool contains(const std::string&) const;
    void insert(const std::string&);
    void remove(const std::string&);

    std::ostream& debug(std::ostream&);

private:
    struct Node;
    using link_t = std::shared_ptr<Node>;

    link_t root_ = nullptr;
    size_t size_ = 0;
};