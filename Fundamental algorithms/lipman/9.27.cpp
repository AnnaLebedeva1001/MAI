#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> fl = {1, 2, 3, 4, 5, 6};
    fl.remove_if([](int i) { return i % 2; });
    for (int i : fl)
        std::cout << i << endl;

    return 0;
}
