// This is a generic version of Int_double_pair. Unlike Int_double_pair,
// which holds an int and a double, Pair can hold any two types. In
// particular, Pair<T1, T2> holds a T1 and a T2.

template <typename T1, typename T2>
struct Pair
{
    Pair(const T1&, const T2&);

    T1 first;
    T2 second;
};

// Equality and inequality on pairs requires equality on T1 and T2
template <typename T1, typename T2>
bool operator==(const Pair<T1, T2>&, const Pair<T1, T2>&);

template <typename T1, typename T2>
bool operator!=(const Pair<T1, T2>&, const Pair<T1, T2>&);

// Comparisons in pairs require operator< to be defined for both T1 and T2.
template <typename T1, typename T2>
bool operator< (const Pair<T1, T2>&, const Pair<T1, T2>&);

template <typename T1, typename T2>
bool operator<=(const Pair<T1, T2>&, const Pair<T1, T2>&);

template <typename T1, typename T2>
bool operator> (const Pair<T1, T2>&, const Pair<T1, T2>&);

template <typename T1, typename T2>
bool operator>=(const Pair<T1, T2>&, const Pair<T1, T2>&);

/////
///// IMPLEMENTATION
///// When defining templates, the implementation has to go in the header.
/////

template <typename T1, typename T2>
Pair<T1, T2>::Pair(const T1& v1, const T2& v2)
        : first(v1), second(v2)
{ }

template <typename T1, typename T2>
bool operator==(const Pair<T1, T2>& a, const Pair<T1, T2>& b)
{
    return a.first == b.first && a.second == b.second;
}

template <typename T1, typename T2>
bool operator!=(const Pair<T1, T2>& a, const Pair<T1, T2>& b)
{
    return !(a == b);
}

template <typename T1, typename T2>
bool operator< (const Pair<T1, T2>& a, const Pair<T1, T2>& b)
{
    if (a.first < b.first) return true;
    if (b.first < a.first) return false;
    return a.second < b.second;
}

template <typename T1, typename T2>
bool operator<=(const Pair<T1, T2>& a, const Pair<T1, T2>& b)
{
    return !(b < a);
}

template <typename T1, typename T2>
bool operator> (const Pair<T1, T2>& a, const Pair<T1, T2>& b)
{
    return b < a;
}

template <typename T1, typename T2>
bool operator>=(const Pair<T1, T2>& a, const Pair<T1, T2>& b)
{
    return !(a < b);
}
