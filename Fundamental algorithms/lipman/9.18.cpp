#include <iostream>
#include <deque>
#include <iterator>
#include <string>

using namespace std;

int main()
{
    deque <string> deq;
    deque <string>::iterator it;
    string str;
    while(getline(cin, str))
    {
        deq.push_back(str);
    }
    for(it = deq.begin(); it != deq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}