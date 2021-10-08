#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

bool isShorter(const int &s1, const int &s2)
{
    return s1 < s2;
}

void elimDups(vector<int> & obj )
{

    stable_sort(obj.begin(), obj.end(), isShorter);
    //auto end_unique = unique( obj.begin(), obj.end() );
    //obj.erase(end_unique, obj.end());
}


int main()
{
    vector <int> v;
    int n;
    while(cin >> n)
    {
        v.push_back(n);
    }
    elimDups(v);
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}