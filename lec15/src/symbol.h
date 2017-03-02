/*
 * This file demonstrates two patterns: flyweight and singleton.
 *
 * The symbol class is a flyweight class, because it stores a pointer to its
 * state rather than the state itself. If we have multiple symbols with the
 * same name (string), they will share that string in their representations.
 *
 * The Symbol_table class is a singleton, because there will be exactly one
 * instance of it, accessed via the static function Symbol_table::instance().
 * This is because we want all symbols to share the same Symbol_table.
 */
#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

class Symbol_table;

class symbol
{
public:
    const std::string& name() const { return ptr_->name; }

    bool operator==(const symbol& that) const
    {
        return ptr_ == that.ptr_;
    }

private:
    struct repr
    {
        repr(const std::string& n) : name(n) { }
        std::string name;
    };

    std::shared_ptr<repr> ptr_;

    symbol(const std::shared_ptr<repr>& ptr) : ptr_{ptr} { }

    friend class Symbol_table;
};

inline bool operator!=(const symbol& a, const symbol& b)
{
    return !(a == b);
}

inline std::ostream& operator<<(std::ostream& stream, const symbol& sym)
{
    return stream << sym.name();
}

class Symbol_table
{
public:
    static Symbol_table& instance();

    symbol intern(const std::string&);
    void clean();

    Symbol_table(const Symbol_table&) = delete;
    Symbol_table& operator=(const Symbol_table&) = delete;

private:
    Symbol_table() {}
    ~Symbol_table() {}

    std::unordered_map<std::string, std::weak_ptr<symbol::repr>> table_;
};

symbol intern(const std::string&);
