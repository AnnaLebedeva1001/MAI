#include <iostream>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector <int> vec = {1, 2, 3};
    cout << vec[0] << endl;
    cout << vec.at(0) << endl;
    cout << vec.front() << endl;
    vec.begin();

    return 0;
}