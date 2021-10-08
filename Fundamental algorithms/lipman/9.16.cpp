#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    vector<int> v1 = {1, 2, 3, 4};
    list<int> l2 = {1, 2, 3, 5};
    vector <int>::iterator itv;
    list <int>::iterator itl;

    if (v1.size() == l2.size())
    {
        for(itv = v1.begin(), itl = l2.begin(); itv != v1.end(), itl != l2.end(); itv++, itl++)
        {
            if (*itv == *itl) continue;
            else
            {
                cout << "False" << endl;
                return 0;
            }
        }
        cout << "True" << endl;
    }
    else cout << "False" << endl;

    return 0;
}