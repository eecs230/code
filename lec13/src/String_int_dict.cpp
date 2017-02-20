#include "String_int_dict.h"

using namespace std;

namespace dictionary {

struct String_int_dict::Node
{
    string key;
    int value;
    Node* left;
    Node* right;

    Node(const string& k, int v, Node* l, Node* r)
            : key(k), value(v), left(l), right(r)
    { }

    static void deep_delete(Node*);
    static Node* deep_clone(const Node*);

    static void get_keys_helper(Node*, vector<string>&);

    static Node* find(Node*, const string&);
    static Node** find_mut(Node**, const string&);
};

String_int_dict::String_int_dict(
        initializer_list<std::pair<string, int>> mappings)
{
    for (const std::pair<string, int>& each : mappings)
        insert(each.first, each.second);
}

String_int_dict::String_int_dict(const String_int_dict& that)
        : size_(that.size_),
          root_(Node::deep_clone(that.root_))
{ }

String_int_dict& String_int_dict::operator=(const String_int_dict& that)
{
    Node::deep_delete(root_);
    size_ = that.size_;
    root_ = Node::deep_clone(that.root_);

    return *this;
}

String_int_dict::~String_int_dict()
{
    Node::deep_delete(root_);
}

bool String_int_dict::empty() const {
    return root_ == nullptr;
}

size_t String_int_dict::size() const {
    return size_;
}

void String_int_dict::clear()
{
    Node::deep_delete(root_);
    root_ = nullptr;
    size_ = 0;
}

bool String_int_dict::has_key(const string& key) const
{
    return Node::find(root_, key) != nullptr;
}

const int* String_int_dict::find(const string& key) const
{
    Node* node = Node::find(root_, key);
    if (node == nullptr) return nullptr;
    else return &node->value;
}

int* String_int_dict::find(const string& key)
{
    Node* node = Node::find(root_, key);
    if (node == nullptr) return nullptr;
    else return &node->value;
}

void String_int_dict::insert(const string& key, int value)
{
    Node** node = Node::find_mut(&root_, key);

    if (*node == nullptr) {
        *node = new Node(key, value, nullptr, nullptr);
        ++size_;
    } else {
        (*node)->value = value;
    }
}

int& String_int_dict::operator[](const string& key)
{
    Node** node = Node::find_mut(&root_, key);

    if (*node == nullptr) {
        *node = new Node(key, 0, nullptr, nullptr);
        ++size_;
    }

    return (*node)->value;
}

void String_int_dict::Node::get_keys_helper(Node* node, vector<string>& out)
{
    if (node != nullptr) {
        Node::get_keys_helper(node->left, out);
        out.push_back(node->key);
        Node::get_keys_helper(node->right, out);
    }
}

vector<string> String_int_dict::get_keys() const
{
    vector<string> result;
    Node::get_keys_helper(root_, result);
    return result;
}

void String_int_dict::Node::deep_delete(Node* node)
{
    if (node) {
        Node::deep_delete(node->left);
        Node::deep_delete(node->right);
        delete node;
    }
}

String_int_dict::Node*
String_int_dict::Node::deep_clone(const Node* node)
{
    if (node)
        return new Node(node->key, node->value,
                        Node::deep_clone(node->left),
                        Node::deep_clone(node->right));
    else
        return nullptr;
}

String_int_dict::Node*
String_int_dict::Node::find(Node* node, const string& key)
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

String_int_dict::Node**
String_int_dict::Node::find_mut(Node** node, const string& key)
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
