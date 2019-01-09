#pragma once

#include <iostream>
#include <memory>
#include <string>

namespace matcher {

using std::string;

struct IMatcher {
    virtual bool matches(const string&) const = 0;
    virtual void describe(std::ostream&) const = 0;
};

std::ostream& operator<<(std::ostream&, const IMatcher&);
std::string to_string(const IMatcher&);

using Matcher = std::shared_ptr<IMatcher>;

Matcher operator&&(Matcher, Matcher);
Matcher operator||(Matcher, Matcher);
Matcher operator!(Matcher);

Matcher equals(const string&);
Matcher substring_at(const string&, size_t);
Matcher starts_with(const string&);
Matcher ends_with(const string&);
Matcher contains(const string&);

}