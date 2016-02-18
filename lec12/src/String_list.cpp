#include "String_list.h"

namespace string_list {

struct Node
{
    std::string           first;
    std::shared_ptr<Node> rest;
};

String_list::String_list()
        : head_{nullptr}
{ }

String_list::String_list(std::string first, String_list rest)
        : head_{new Node{first, rest.head_}}
{ }

String_list::String_list(std::shared_ptr<Node> head)
        : head_{head}
{ }

bool String_list::is_empty() const
{
    return head_ == nullptr;
}

const std::string& String_list::first() const
{
    return (*head_).first;
}

String_list String_list::rest() const
{
    return (*head_).rest;
}

const String_list empty;

String_list cons(std::string first, String_list rest)
{
    return String_list{first, rest};
}

size_t length(String_list lst)
{
    size_t result = 0;

    while (!lst.is_empty()) {
        ++result;
        lst = lst.rest();
    }

    return result;
}

} // namespace string_list
