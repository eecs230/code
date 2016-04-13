#pragma once

#include <memory>

class Int_bst
{
public:
    Int_bst();

    bool is_empty() const;
    size_t size() const;

    bool contains(int) const;
    void insert(int);
    void remove(int);

private:
    struct Node;
    std::shared_ptr<Node> root_;

    friend size_t size_helper(std::shared_ptr<Node>);
};