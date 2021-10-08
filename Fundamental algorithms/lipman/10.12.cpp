#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Sales_data
{
public:
    int isbn;
    Sales_data(int x)
    {
        isbn = x;
    }

    friend bool compareisbn(const Sales_data& right, const Sales_data& left);
    friend ostream& operator<<(ostream& stream, const Sales_data& m);
};

bool compareisbn(const Sales_data& right, const Sales_data& left)
{

    return right.isbn > left.isbn;
}

ostream& operator<<(ostream& stream, const Sales_data& m)
{
    cout << m.isbn;
    return stream;
}

int main()
{
    vector<Sales_data> b;
    Sales_data fir(1);
    Sales_data sec(2);
    Sales_data thir(3);
    b.push_back(fir);
    b.push_back(sec);
    b.push_back(thir);
    for (const auto& c : b)
        cout << c << " ";
    cout << endl;
    stable_sort(b.begin(), b.end(),compareisbn);
    for (const auto& c : b)
        cout << c << " ";
    cout << endl;
    return 0;
}