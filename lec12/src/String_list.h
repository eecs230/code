#pragma once

#include <memory>
#include <string>

namespace string_list {

struct Node;

class String_list
{
public:
    String_list();
    String_list(std::string first, String_list rest);

    bool is_empty() const;

    const std::string& first() const;
    String_list rest() const;

private:
    std::shared_ptr<Node> head_;

    String_list(std::shared_ptr<Node>);
};

extern const String_list empty;
String_list cons(std::string first, String_list rest);

size_t length(String_list);

} // end namespace string_list
