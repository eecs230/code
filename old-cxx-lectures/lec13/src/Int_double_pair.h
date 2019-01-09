// This is an example of a simple monomorphic class for storing a pair of an
// int and a double. See Pair.h for a generic version of this.

struct Int_double_pair
{
    Int_double_pair(int, double);

    int first;
    double second;
};

bool operator==(const Int_double_pair&, const Int_double_pair&);
bool operator!=(const Int_double_pair&, const Int_double_pair&);
bool operator< (const Int_double_pair&, const Int_double_pair&);
bool operator<=(const Int_double_pair&, const Int_double_pair&);
bool operator> (const Int_double_pair&, const Int_double_pair&);
bool operator>=(const Int_double_pair&, const Int_double_pair&);
