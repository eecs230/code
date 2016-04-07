#include <eecs230.h>

int main()
{
    vector<int> v;

    cout << "Enter some numbers, ending with 0> ";

    int n;
    while (cin >> n && n != 0) {
        v.push_back(n);
    }

    for (int i = 0; i < v.size(); ++i) {
        cout << v[v.size() - 1 - i] << "\n";
    }

}
