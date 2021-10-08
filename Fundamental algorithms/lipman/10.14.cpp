#include <iostream>

using namespace std;

int main()
{
    auto addNumbers{
        [](double a, double b) {
            return (a + b);
        }};

    cout << addNumbers(5, 6) << endl;
    return 0;
}