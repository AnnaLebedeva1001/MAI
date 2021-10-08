#include <iostream>

using namespace std;

void change(string& s, string oldVal, string newVal)
{
    string::size_type iter = 0;
    while((iter = s.find(oldVal, iter)) != string::npos)
    {
        s.erase(iter, oldVal.size());
        s.insert(iter, newVal);
        ++iter;
    }
}

int main()
{
    string s = "tho who why tho thru cuda?";
    change(s, "tho", "through");
    cout << s << endl;
    return 0;
}
