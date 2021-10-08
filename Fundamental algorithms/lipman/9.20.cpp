#include <iostream>
#include <list>
#include <iterator>
#include <deque>
#include <vector>

using namespace std;

int main()
{
    list <int> lis = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque <int> deq1;
    deque <int> deq2;
    deque <int>::iterator it2;
    vector <int> vec;
    vec.assign(lis.begin(), lis.end());

    for(int i = 0; i < lis.size(); i++)
    {
        if (i % 2 == 0)
        {
            deq1.push_back(vec[i]);
        }
        else
        {
            deq2.push_back(vec[i]);
        }
        
    }

    for(it2 = deq1.begin(); it2 != deq1.end(); it2++)
    {
        cout << *it2 << " ";
    }
    cout << endl;

    for(it2 = deq2.begin(); it2 != deq2.end(); it2++)
    {
        cout << *it2 << " ";
    }
    cout << endl;

    return 0;
}