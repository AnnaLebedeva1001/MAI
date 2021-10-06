#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <iconv.h>
#include <errno.h>
#include <err.h>
#include "socket.h"

using namespace std;

string read_file(string file_name)
{
    ifstream fin{file_name};
    string res;

    char ch;
    while ((ch = fin.get()) != EOF)
        res += ch;

    return res;
}

string iconv(string code_from, string code_to, string code)
{
    iconv_t cd;
    size_t k, f, t;
    int se;
    int need_size = code.length();
    char* in = (char*)code.c_str();
    char buf[need_size*2];
    char* out = buf;
 
    cd = iconv_open(code_to.c_str(), code_from.c_str());
    if (cd == (iconv_t)(-1)) err(1, "iconv_open");
    f = strlen(code.c_str());
    t = sizeof buf;
    errno = 0;
    k = iconv(cd, &in, &f, &out, &t);
    se = errno;
 
    iconv_close(cd);
 
    return buf;
}

void convert(char *file_name, char *code_from, char *code_to)
{
    Address addr{port, host_name};
    Socket socket;

    socket.connect(addr);

    Package package{Command::send_filename};
    package.fragment_size = strlen(file_name) + 1;
    strcpy(package.data, file_name);
    socket.write(package);

    string text{read_file(file_name)};

    string conv_text{iconv(code_from, code_to, text)};

    package.cmd = Command::send_file;
    package.num_of_fragments = conv_text.size() / Package::MAX_FRAGMENT_SIZE + bool(conv_text.size() % Package::MAX_FRAGMENT_SIZE);
    size_t i{};

    package.fragment_size = Package::MAX_FRAGMENT_SIZE;
    for (package.fragment_num = 0; package.fragment_num < conv_text.size() / Package::MAX_FRAGMENT_SIZE; ++package.fragment_num)
    {
        for (int j{}; j < Package::MAX_FRAGMENT_SIZE; ++i, ++j)
            package.data[j] = conv_text[i];

        socket.write(package);
    }

    package.clear_data();

    package.fragment_size = conv_text.size() % Package::MAX_FRAGMENT_SIZE;
    for (int j{}; i < conv_text.size(); ++i, ++j)
        package.data[j] = conv_text[i];

    socket.write(package);

    socket.write(Package(Command::check));

    socket.read(package);

    if (strcmp(file_name, package.data))
        error("bad file name");

    socket.write(Package(Command::stop));
}

int main()
{
    char enter[BUFSIZ], code_from[BUFSIZ], code_to[BUFSIZ];
    cout << "Enter file name: ";
    cin >> enter;

    cout << "Enter file encoding: ";
    cin >> code_from;

    cout << "Enter the encoding you want to convert to: ";
    cin >> code_to;

    convert(enter, code_from, code_to);

    return 0;
}
