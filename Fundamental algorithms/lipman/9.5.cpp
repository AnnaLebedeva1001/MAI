#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<int>::iterator function(vector<int>::iterator first, vector<int>::iterator last, int val)
{
    while (first != last)
    {
        if (*first == val)
            return first;
        ++first;
    }
    return last;
}

int main()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    vector<int>::iterator it1 = v1.begin(), it2 = v1.end(), it;

    it = function(it1, it2, 40);

    cout << *it << endl;

    return 0;
}