#include <iostream>
#include <forward_list>
#include <iterator>
#include <algorithm>

using namespace std;

int func(forward_list<string> &fl, string const &s1, string const &s2)
{
    auto begin = fl.begin(), prev = fl.before_begin();

    while (begin != fl.end())
    {
        ++begin;
        ++prev;
    }
    auto it = find(fl.begin(), fl.end(), s1);
    if (it == fl.end())
        fl.insert_after(prev, s2);
    else
    {
        fl.insert_after(it, s2);
    }
    return 0;
}

int main()
{
    forward_list<string> fl = {"fiit", "one", "love", "forever"};
    string s1 = "fiit";
    string s2 = "top";
    func(fl, s1, s2);
    forward_list<string>::iterator it;
    for (it = fl.begin(); it != fl.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}
