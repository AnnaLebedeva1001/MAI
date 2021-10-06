#include <cstdlib>
#include <cstdio>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>
#include <netdb.h>

constexpr int port{20001};
constexpr char *host_name{"localhost"};

void error(const char *msg)
{
    perror(msg);
    perror("\n");
    exit(1);
}

enum class Command : char
{
    send_filename = 0X00, // передать имя файла
    send_file = 0X01,     // отправляем файл
    check = 0X10,         // передаем сигнал о завершении запросов
    stop = 0X11           // остановка сервера
};

struct Package
{
    static constexpr size_t MAX_FRAGMENT_SIZE{1024};

    char protocol_code{42};
    Command cmd;
    int32_t num_of_fragments;
    int32_t fragment_num;
    int16_t fragment_size;
    char data[MAX_FRAGMENT_SIZE];

    Package()
        : num_of_fragments{1}, fragment_num{1}, fragment_size{}
    {
        bzero(data, MAX_FRAGMENT_SIZE);
    }

    explicit Package(Command cmd_) : Package()
    {
        cmd = cmd_;
    }

    void clear_data()
    {
        bzero(data, MAX_FRAGMENT_SIZE);
    }
};

class Address
{
    hostent *_name_to_host(const char *name)
    {
        hostent *host{gethostbyname(name)};

        if (!host)
            error("no such host");

        return host;
    }

public:
    sockaddr_in addr;

    Address() = default;

    explicit Address(int port, const char *name = "")
    {
        // адрес структуры инициализации

        bzero((char *)&addr, sizeof(addr));

        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);

        if (strlen(name))
        {
            hostent *host{_name_to_host(name)};

            bcopy((char *)host->h_addr, (char *)&addr.sin_addr.s_addr, host->h_length);

            return;
        }

        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
    }
};

class Socket
{
    int _sockfd;

public:
    Socket()
    {
        _sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (_sockfd < 0)
            error("can't open socket");
    }

    explicit Socket(int sockfd) : _sockfd{sockfd}
    {
    }

    void connect(Address const &addr)
    {

        if (::connect(_sockfd, (sockaddr *)&addr.addr, sizeof(addr.addr)) < 0)
            error("can't connect");
    }

    void bind(Address const &addr)
    {

        if (::bind(_sockfd, (sockaddr *)&addr.addr, sizeof(addr.addr)) < 0)
            error("can't bind");
    }

    void listen()
    {
        ::listen(_sockfd, 1);
    }

    Socket accept(Address const &addr)
    {
        socklen_t addr_len{sizeof(addr.addr)};

        int new_sockfd{::accept(_sockfd, (sockaddr *)&addr.addr, &addr_len)};

        if (new_sockfd < 0)
            error("can't accept");

        return Socket(new_sockfd);
    }

    void write(const Package &package)
    {
        if (::write(_sockfd, &package, sizeof(Package)) < 0)
            error("can't write");
    }

    void read(Package &package)
    {
        if (::read(_sockfd, &package, sizeof(Package)) < 0)
            error("can't read");
    }

    ~Socket()
    {
        close(_sockfd);
    }
};