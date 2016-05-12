#pragma once

#include <memory>
#include <string>

namespace list {

class String_list_node {
public:
    using String_list = std::shared_ptr<String_list_node>;

    String_list_node(std::string first, String_list rest);

    const std::string& first() const;
    String_list rest() const;

private:
    std::string first_;
    String_list rest_;

public:
    class iterator {
    public:
        iterator& operator++();
        iterator operator++(int);
        const std::string& operator*() const;

        friend class String_list_node;
        friend bool operator==(iterator, iterator);

    private:
        iterator(const String_list_node*);
        const String_list_node* ptr_;
    };

    iterator begin() const;
    iterator end() const;
};

using String_list = String_list_node::String_list;

bool operator==(String_list_node::iterator, String_list_node::iterator);
bool operator!=(String_list_node::iterator, String_list_node::iterator);

String_list cons(std::string first, String_list rest);
const std::string& first(String_list);
String_list rest(String_list);

String_list_node::iterator begin(String_list);
String_list_node::iterator end(String_list);

size_t length(String_list);

String_list append(String_list, String_list);
String_list reverse(String_list);

bool operator==(String_list, String_list);

} // end cons_list
