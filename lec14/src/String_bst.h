#pragma once

#include <memory>
#include <string>

class String_bst
{
public:
    String_bst();

    bool is_empty() const;
    size_t size() const;

    bool contains(const std::string&) const;
    void insert(std::string);
    void remove(const std::string&);

private:
    struct Node;
    std::shared_ptr<Node> root_;

    friend size_t size_helper(std::shared_ptr<Node>);
};