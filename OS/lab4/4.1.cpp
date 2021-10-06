#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <ctime>
#include <random>

using namespace std;

#define KEY 44
#define SEMSIZE 2

union semun
{
    int val;
    semid_ds *mbuf;
    ushort *array;
    seminfo *ibuf;
} arg;


int main(int argc, char** argv)
{
    srandom(time(0));
    long long int st_time = time(0);
    ushort arr[BUFSIZ];
    arg.array = arr;

    if(argc == 1)
    {
        perror("No input file");
        exit(1);
    }
    else if(argc > 2)
    {
        perror("A lot of arguments!");
        exit(2);
    }

    ofstream File(argv[1]);
    if(!File.is_open())
    {
        perror("Can't open input file!");
        exit(3);
    }
    File.close();

    sembuf sopS[1] = {{1, 1, 0}};
    sembuf sopr1[2] = {{0, 1, 0}, {1, -1, IPC_NOWAIT}};
    sembuf sopr2[1] = {{1, 1, 0}};
    sembuf sopr3[1] = {{0, -1, 0}};
    sembuf sopw1[1] {{1, -1, IPC_NOWAIT}};
    sembuf sopw2[1] {{0, 0, 0}};
    sembuf sopw3[1] = {{1, 1, 0}};

    int sem_desk;
    if((sem_desk = semget(KEY, SEMSIZE, IPC_CREAT | 0777)) == -1)
    {
        perror("Semget fail");
        exit(4);
    }

    if (semop(sem_desk, sopS, 1) == -1)
    {
        perror("Semop fail");
        exit(3);
    }

    pid_t pid;
    int ppid = getpid();
    int k, id;
    long long int count;
    for(int i = 0; i < 20; i++)
    {
        pid = fork();
        if(pid == -1)
        {
            perror("Fork Error\n");
            exit(5);
        }
        else if(pid == 0)
        {
            k = i % 2;
            id = i / 2;
            count = 0;
            break;
        }
    }

    if(getpid() == ppid)
    {
        sleep(30);

        if (semctl(sem_desk, 0, IPC_RMID, 0) == -1)
        {
            perror("Semctl fail");
            exit(7);
        }
        return 0;
    }

    while((time(0) - st_time) < 30)
    {
        usleep(rand() % 10000 + 10000);
        if(k)
        {
            if (semop(sem_desk, sopw1, 1) != -1) {
                semop(sem_desk, sopw2, 1);

                ofstream File(argv[1], ios::app);
                File << random() % 1000 << endl;
                count++;
                if(!File.is_open())
                {
                    File.close();
                }
                semop(sem_desk, sopw3, 1);
            }
        }
        else
        {
            if (semop(sem_desk, sopr1, 2) != -1) {
                semop(sem_desk, sopr2, 1);

                ifstream File(argv[1], ios::app);
                char curr;
                while(File >> curr)
                {
                    if((curr - '0') == id)
                    {
                        count++;
                    }
                }
                if(!File.is_open())
                {
                    File.close();
                }
                semop(sem_desk, sopr3, 1);
            }
        }
    }
    cout << "I am  " << ((k == 1) ? "Writer" : "Reader") << ", PID: " << getpid() << ", Count: "<< count << endl;
}