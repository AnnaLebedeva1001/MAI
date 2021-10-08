#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> v = {1, 1, 5, 6, 4, 7, 7};
    list <int> l;
    //forward_list <int> fl;
    vector <int> fl;
    deque <int> d;
    copy(v.begin(), v.end(), inserter(l, l.begin()));
    copy(v.begin(), v.end(), inserter(fl, fl.begin()));
    copy(v.begin(), v.end(), inserter(d, d.begin()));
    for(auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    for(auto it = fl.begin(); it != fl.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    for(auto it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;


    copy(v.begin(), v.end(), back_inserter(l));
    copy(v.begin(), v.end(), back_inserter(fl));
    copy(v.begin(), v.end(), back_inserter(d));
    for(auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    for(auto it = fl.begin(); it != fl.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    for(auto it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;


    copy(v.begin(), v.end(), front_inserter(l));
    //copy(v.begin(), v.end(), front_inserter(fl));
    copy(v.begin(), v.end(), front_inserter(d));
    for(auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    /*for(auto it = fl.begin(); it != fl.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;*/
    for(auto it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}