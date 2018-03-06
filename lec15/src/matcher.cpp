#include "matcher.h"
#include <algorithm>
#include <functional>
#include <sstream>

using namespace std;

namespace matcher {

std::ostream& operator<<(std::ostream& o, const IMatcher& m)
{
    m.describe(o);
    return o;
}

namespace {

struct Quoted
{
    const string& value;
};

ostream& operator<<(ostream& os, Quoted s)
{
    os << '"';
    for (char c : s.value) {
        if (c == '"' || c == '\\')
            os << '\\';
        os << c;
    }
    os << '"';
    return os;
}

class Disjunction_matcher : public IMatcher
{
public:
    Disjunction_matcher(Matcher, Matcher);
    bool matches(const string&) const override;
    void describe(ostream&) const override;
private:
    Matcher left_, right_;
};

Disjunction_matcher::Disjunction_matcher(
        Matcher left, Matcher right)
        : left_(left), right_(right) {}

bool Disjunction_matcher::matches(const string& actual) const
{
    return left_->matches(actual) || right_->matches(actual);
}

void Disjunction_matcher::describe(ostream& os) const
{
    os << "(or " << *left_ << ' ' << *right_ << ')';
}

class Negation_matcher : public IMatcher
{
public:
    Negation_matcher(Matcher);
    bool matches(const string&) const override;
    void describe(ostream&) const override;
private:
    Matcher negation_;
};

Negation_matcher::Negation_matcher(Matcher negation)
        : negation_(negation) {}

bool Negation_matcher::matches(const string& actual) const
{
    return !negation_->matches(actual);
}

void Negation_matcher::describe(ostream& os) const
{
    os << "(not " << *negation_ << ')';
}

class Equals_matcher : public IMatcher
{
public:
    explicit Equals_matcher(const string&);
    bool matches(const string&) const override;
    void describe(ostream&) const override;
private:
    string expected_;
};

matcher::Equals_matcher::Equals_matcher(const string& expected)
        : expected_(expected) {}

bool matcher::Equals_matcher::matches(const string& actual) const
{
    return actual == expected_;
}

void matcher::Equals_matcher::describe(ostream& os) const
{
    os << "(equals " << Quoted{expected_} << ")";
}

class Substring_at_matcher : public IMatcher
{
public:
    Substring_at_matcher(const string&, size_t);
    bool matches(const string&) const override;
    void describe(ostream&) const override;

protected:
    string substring_;
    size_t position_;
};

bool Substring_at_matcher::matches(const string& actual) const
{
    if (position_ + substring_.size() > actual.size())
        return false;

    for (size_t i = 0; i < substring_.size(); ++i) {
        if (substring_[i] != actual[position_ + i])
            return false;
    }

    return true;
}

Substring_at_matcher::Substring_at_matcher(
        const string& substring, size_t position)
        : substring_(substring), position_(position) {}

void Substring_at_matcher::describe(ostream& os) const
{
    os << "(substring-at " << Quoted{substring_} << ' ' << position_ << ')';
}

class Starts_with_matcher : public Substring_at_matcher
{
public:
    explicit Starts_with_matcher(const string&);
    void describe(ostream& os) const override;
};

Starts_with_matcher::Starts_with_matcher(const string& prefix)
        : Substring_at_matcher(prefix, 0) {}

void Starts_with_matcher::describe(ostream& os) const
{
    os << "(starts-with " << Quoted{substring_} << ')';
}

class Ends_with_matcher : public IMatcher
{
public:
    explicit Ends_with_matcher(const string&);
    bool matches(const string&) const override;
    void describe(ostream&) const override;

private:
    string suffix_;
};

Ends_with_matcher::Ends_with_matcher(const string& suffix)
        : suffix_(suffix) {}

bool Ends_with_matcher::matches(const string& actual) const
{
    if (actual.size() < suffix_.size())
        return false;

    size_t offset = actual.size() - suffix_.size();

    return Substring_at_matcher(suffix_, offset).matches(actual);
}

void Ends_with_matcher::describe(ostream& os) const
{
    os << "(ends-with " << Quoted{suffix_} << ')';
}

class Contains_matcher : public IMatcher
{
public:
    explicit Contains_matcher(const string&);
    bool matches(const string&) const override;
    void describe(ostream&) const override;

private:
    string substring_;
};

Contains_matcher::Contains_matcher(const string& substring)
        : substring_(substring) {}

bool Contains_matcher::matches(const string& actual) const
{
    return search(actual.begin(), actual.end(),
                  substring_.begin(), substring_.end())
           != actual.end();
}

void Contains_matcher::describe(ostream& os) const
{
    os << "(contains " << Quoted{substring_} << ')';
}

}

Matcher operator&&(Matcher a, Matcher b)
{
    class Conjunction_matcher : public IMatcher
    {
    public:
        Conjunction_matcher(Matcher left, Matcher right)
                : left_(left), right_(right)
        { }

        bool matches(const string& actual) const
        {
            return left_->matches(actual) && right_->matches(actual);
        }

        void describe(ostream& os) const {
            os << "(and " << *left_ << ' ' << *right_ << ')';
        }

    private:
        Matcher left_, right_;
    };

    return make_shared<Conjunction_matcher>(a, b);
}

namespace {

class Lambda_matcher : public IMatcher
{
public:
    using matches_t = std::function<bool(const string&)>;
    using describe_t = std::function<void(ostream&)>;

    Lambda_matcher(matches_t matches, describe_t describe)
            : matches_(std::move(matches)), describe_(std::move(describe)) {}

private:
    bool matches(const string& s) const override
    {
        return matches_(s);
    }

    void describe(std::ostream& o) const override
    {
        describe_(o);
    }

private:
    matches_t matches_;
    describe_t describe_;
};

} // end namespace

Matcher operator||(Matcher a, Matcher b)
{
    const auto matches = [=](const string& s) {
        return a->matches(s) || b->matches(s);
    };

    const auto describe = [=](ostream& o) {
        o << "(or " << *a << ' ' << *b << ')';
    };

    return make_shared<Lambda_matcher>(matches, describe);
}

Matcher operator!(Matcher a)
{
    return make_shared<Lambda_matcher>(
            [=](const auto& s) { return !a->matches(s); },
            [=](auto& o) { o << "(not " << *a << ')'; });
}

string to_string(const IMatcher& m)
{
    ostringstream ss;
    ss << m;
    return ss.str();
}

Matcher equals(const string& expected)
{
    return make_shared<Equals_matcher>(expected);
}

Matcher substring_at(const string& substring, size_t position)
{
    return make_shared<Substring_at_matcher>(substring, position);
}

Matcher starts_with(const string& prefix)
{
    return make_shared<Starts_with_matcher>(prefix);
}

Matcher ends_with(const string& suffix)
{
    return make_shared<Ends_with_matcher>(suffix);
}

Matcher contains(const string& substring)
{
    return make_shared<Contains_matcher>(substring);
}

}