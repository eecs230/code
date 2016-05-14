#pragma once

#include <initializer_list>
#include <iostream>
#include <memory>

class Bst
{
public:
    Bst() = default;
    Bst(std::initializer_list<int>);

    bool is_empty() const;
    size_t size() const;

    bool contains(int) const;
    void insert(int);
    void remove(int);

    std::ostream& debug(std::ostream&);

private:
    struct Node;
    using link_t = std::shared_ptr<Node>;

    link_t root_ = nullptr;
    size_t size_ = 0;
};