#include <iostream>

using namespace std;

string change(string& s,string oldVal, string newVal)
{
    string result(s);
    size_t pos = result.find(oldVal);
    while(pos != string::npos)
    {
        result.replace(pos, oldVal.size(), newVal);
        pos = result.find(oldVal, pos);
    }

    return result;
}
int main()
{
    string s = "tho who why tho thru cuda?";
    string res;
    res = change(s, "tho", "through");
    cout << res << endl;
    return 0;
}
