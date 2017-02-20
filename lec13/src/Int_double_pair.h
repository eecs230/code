// This is an example of a simple monomorphic class for storing a pair of an
// int and a double. See Pair.h for a generic version of this.

class Int_double_pair
{
public:
    Int_double_pair(int, double);

    int first() const;
    double second() const;

private:
    int first_;
    double second_;
};

bool operator==(const Int_double_pair&, const Int_double_pair&);
bool operator!=(const Int_double_pair&, const Int_double_pair&);
bool operator< (const Int_double_pair&, const Int_double_pair&);
bool operator<=(const Int_double_pair&, const Int_double_pair&);
bool operator> (const Int_double_pair&, const Int_double_pair&);
bool operator>=(const Int_double_pair&, const Int_double_pair&);
