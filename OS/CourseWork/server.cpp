#include <iostream>
#include <fstream>
#include "socket.h"

using namespace std;

int main()
{
    Address server_addr{port};
    Socket listener;

    listener.bind(server_addr);
    listener.listen();

    cout << "Server is running." << endl;

    Address client_addr;
    Socket socket{listener.accept(client_addr)};

    Package package;
    bool stop{false};
    char file_name[Package::MAX_FRAGMENT_SIZE] = "\0";
    ofstream out;

    do
    {
        socket.read(package);

        switch (package.cmd)
        {
        case Command::send_filename:
            strcpy(file_name, package.data);

            cout << "File name: \"";
            cout << file_name << '\"' << endl
                 << endl;

            break;

        case Command::send_file:
            out.open(file_name);
            for (int i{}; i < package.fragment_size; ++i)
                out << package.data[i];
            cout << endl;
            out.close();
            break;

        case Command::check:
            package.fragment_size = strlen(file_name) + 1;
            strcpy(package.data, file_name);
            socket.write(package);
            cout << "File encoding converted successfully!!!" << endl;
            break;

        case Command::stop:
            stop = true;
            break;
        }
    } while (!stop);

    return 0;
}
