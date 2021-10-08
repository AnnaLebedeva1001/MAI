#include <iostream>

using namespace std;
 
int main()
{
    int value = 4;
    
    auto addnumbers([value](int n)
    {
        return n + value;
    });
    
    cout << addnumbers(6) << endl;
}