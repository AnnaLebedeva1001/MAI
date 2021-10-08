#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> v = {1, 1, 5, 6, 4, 7, 7};
    list <int> l;
    unique_copy(v.begin(), v.begin() + v.size(), back_inserter(l));
    for(auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}