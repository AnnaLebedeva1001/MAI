#include <iostream>
#include <list>
#include <iterator>
#include <string>

using namespace std;

int main()
{
    list <string> lis;
    list <string>::iterator it;
    string str;
    while(getline(cin, str))
    {
        lis.push_back(str);
    }
    for(it = lis.begin(); it != lis.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}