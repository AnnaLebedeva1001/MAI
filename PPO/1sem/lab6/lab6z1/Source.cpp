#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
    try
    {
        setlocale(LC_CTYPE, "Rus");
        string str;
        size_t count = 0;

        string file_name = "test_6.txt";
        fstream f;

        f.open(file_name);
        if (!f.is_open())
        {
            cout << "Error opening file" << endl;
            return 1;
        }

        for (f >> str; !f.eof(); f >> str)
        {
            int len = str.length();
            if (str[len - 1] == ',')
            {
                count++;
                break;
            }
            count++;
        }

        cout << "count = " << count << endl;
        f.close();
    }
    catch (std::exception err)
    {
        cout << "ERROR" << err.what() << endl;;
    }
    return 0;
}