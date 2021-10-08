#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main()
{
    list <char *> lis = {"a", "an", "the"};
    vector <string> vec;
    vec.assign(lis.begin(), lis.end());
    for (int i = 0; i != vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}