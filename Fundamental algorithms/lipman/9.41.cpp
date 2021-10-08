#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<char> v = {'f', 'i', 'i', 't'};
    string s;
    for(int i = 0; i < v.size(); i++)
    {
        s += v[i];
    }
    cout << s << endl;
    return 0;
}