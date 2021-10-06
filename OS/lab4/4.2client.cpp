#include <iostream>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string>

using namespace std;

#define SEMKEY 88
#define SHMKEY 97
#define SEMSIZE 2

union semun
{
    int val;
    semid_ds *mbuf;
    ushort *array;
    seminfo *ibuf;
} arg;

bool is_double(string str)
{
    char *err_checker = nullptr;
    double value = strtod(str.c_str(), &err_checker);
    if (err_checker == str.c_str() || *err_checker != '\0')
        return 0;
    return 1;
}

bool is_operation(string str)
{
    if (str.length() != 1)
        return 0;
    if (str[0] != '+' && str[0] != '-' && str[0] != '/' && str[0] != '*')
        return 0;
    return 1;
}

int main()
{
    shmid_ds sbuf;
    double *op1, *op2;
    char *opt, *shmptr;
    string tmp1, tmp2, tmpc;
    int shmd, semd, passed = 0;
    ushort arr[BUFSIZ];
    arg.array = arr;

    sembuf sop1[2]{{0, 0, 0}, {1, -1, 0}};
    sembuf sop2[2]{{0, 1, 0 | IPC_NOWAIT}, {1, 0, 0 | IPC_NOWAIT}};
    sembuf sop3[2]{{0, -1, 0}, {1, -1, 0}};
    sembuf sop4[2]{{0, 0, 0 | IPC_NOWAIT}, {1, 1, 0 | IPC_NOWAIT}};

    while (!passed)
    {
        cout << "Enter your expression (operand expression operand):" << endl;
        cin >> tmp1 >> tmpc >> tmp2;
        if (is_double(tmp1) && is_operation(tmpc) && is_double(tmp2))
            passed = 1;
        if (!passed)
            cout << "Invalid enter, try again" << endl;
    }

    if ((shmd = shmget(SHMKEY, (sizeof(double) * 2 + sizeof(char)), 0777 | IPC_CREAT)) == -1)
    {
        perror("Shmget error");
        exit(-15);
    }

    if ((semd = semget(SEMKEY, SEMSIZE, 0777)) == -1)
    {
        perror("Semget error");
        exit(-3);
    }
    if (semop(semd, sop1, 2) == -1)
    {
        perror("Semop error");
        exit(-6);
    }

    if (shmctl(shmd, SHM_UNLOCK, &sbuf) == -1)
    {
        perror("Shmctl error");
        exit(-23);
    }

    shmptr = (char *)shmat(shmd, 0, 0);

    if (shmptr == ((char *)-1))
    {
        perror("Shmat error");
        exit(-45);
    }

    op1 = (double *)shmptr;
    opt = (char *)(op1 + sizeof(double));
    op2 = (double *)(opt + sizeof(char));
    *op1 = stod(tmp1);
    *opt = tmpc[0];
    *op2 = stod(tmp2);

    if (shmdt(shmptr) == -1)
    {
        perror("Shmdt error(1)");
        exit(-34);
    }

    if (shmctl(shmd, SHM_UNLOCK, &sbuf) == -1)
    {
        perror("Shmctl error");
        exit(-46);
    }

    if (shmctl(shmd, SHM_LOCK, &sbuf) == -1)
    {
        perror("Shmctl error");
        exit(-35);
    }

    if (semop(semd, sop2, 2) == -1)
    {
        perror("Semop error");
        exit(-15);
    }

    if (semop(semd, sop3, 2) == -1)
    {
        perror("Semop error");
        exit(-66);
    }


    if (semop(semd, sop4, 2) == -1)
    {
        perror("Semop error");
        exit(-77);
    }

    shmptr = (char *)shmat(shmd, 0, 0);

    if (shmptr == ((char *)-1))
    {
        perror("Shmat error");
        exit(-27);
    }

    op1 = (double *)shmptr;
    cout << *op1 << endl;

    if (shmdt(op1) == -1)
    {
        perror("Shmdt error(1)");
        exit(-24);
    }

    if (shmctl(shmd, SHM_LOCK, &sbuf) == -1)
    {
        perror("Shmctl error");
        exit(-52);
    }

}
