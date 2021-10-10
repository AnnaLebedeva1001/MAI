#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    try
    {
        setlocale(LC_CTYPE, "Rus");
        string str, word, file_name = "test_6_1.txt";
        fstream f;
        vector <string> vector(6);
        int i;

        f.open(file_name);
        if (!f.is_open())
        {
            cout << "Error opening file" << endl;
            return 1;
        }

        while (!f.eof())
        {
            i = 0;
            for (f >> word; ; f >> word)
            {
                vector[i] = word;
                i++;
                if (i == 6) break;
            }
            if (vector[0] == "Moskovskaya" && vector[3] == "15" && vector[4] == "May" && vector[5] == "1997")
            {
                for (i = 0; i < vector.size(); i++)
                {
                    cout << vector[i] << " ";
                }
                cout << endl;
            }
        }

        f.close();
    }
    catch (std::exception err)
    {
        cout << "ERROR" << err.what() << endl;;
    }
    return 0;
}