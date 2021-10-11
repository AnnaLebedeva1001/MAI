#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    cout << "Enter whole numbers(the input will stop at the first error and the list will be sorted):" << endl;
    list<int> l;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(l));
    l.sort();
    copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}