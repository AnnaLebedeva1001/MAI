#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    fstream input("29_test.txt");
    vector<string> vec;
    copy(istream_iterator<string> (input), istream_iterator<string> (), back_inserter(vec));
    copy(vec.begin(), vec.end(), ostream_iterator<string> (cout, " "));
    cout << endl;
}