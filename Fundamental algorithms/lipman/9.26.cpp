#include <iostream>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> v1;
    list<int> l2;
    for(int i = 0; i < 11; i++)
    {
        v1.push_back(ia[i]);
        l2.push_back(ia[i]);
    }

    auto itv = v1.begin();
    while (itv != v1.end())
    {
        if (*itv % 2) 
            itv = v1.erase(itv);
        else
            itv++;
    }

    for (itv = v1.begin(); itv != v1.end(); itv++)
    {
        cout << *itv << " ";
    }
    cout << endl;
    
    auto itl = l2.begin();
    while (itl != l2.end())
    {
        if (*itl % 2) 
            itl++;
        else
            itl = l2.erase(itl);
    }

    for (itl = l2.begin(); itl != l2.end(); itl++)
    {
        cout << *itl << " ";
    }
    cout << endl;


    return 0;
}