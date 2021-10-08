#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

bool comp (int a, int b)
{
  return a < b;
}

int main()
{
    int n;
    vector<int> vec;
    copy(istream_iterator<int> (cin >> n), istream_iterator<int> (), back_inserter(vec));
    sort(vec.begin(), vec.end(), comp);
    copy(vec.begin(), vec.end(), ostream_iterator<int> (cout, " "));
    cout << endl;
}