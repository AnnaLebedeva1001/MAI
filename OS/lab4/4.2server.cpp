#include <iostream>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

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

int main()
{
    ushort arr[BUFSIZ];
    arg.array = arr;
    shmid_ds sbuf;
    double *op1, *op2;
    char *opt, *shmptr;
    int shmdesk, semdesk;

    sembuf sopS[1] = {{1, 1, 0}};
    sembuf sop1[2]{{0, -1, 0}, {1, 0, 0}};
    sembuf sop2[2]{{0, 0, 0 | IPC_NOWAIT}, {1, 0, 0 | IPC_NOWAIT}};
    sembuf sop3[2]{{0, 1, 0 | IPC_NOWAIT}, {1, 1, 0 | IPC_NOWAIT}};

    if ((shmdesk = shmget(SHMKEY, (sizeof(double) * 2 + sizeof(char)), 0777)) != -1)
    {
        if (shmctl(shmdesk, IPC_RMID, &sbuf) == -1)
        {
            perror("Shmctl error");
            exit(10);
        }
    }

    if ((shmdesk = shmget(SHMKEY, (sizeof(double) * 2 + sizeof(char)), 0777 | IPC_CREAT)) == -1)
    {
        perror("Shmget error");
        exit(20);
    }

    if (shmctl(shmdesk, SHM_LOCK, &sbuf) == -1)
    {
        perror("Shmctl error");
        exit(50);
    }

    if ((semdesk = semget(SEMKEY, SEMSIZE, 0777)) != -1)
    {
        if (semctl(semdesk, 0, IPC_RMID, 0) == -1)
        {
            perror("Semctl error");
            exit(-1);
        }
    }

    if ((semdesk = semget(SEMKEY, SEMSIZE, IPC_CREAT | 0777)) == -1)
    {
        perror("Semget error");
        exit(-2);
    }

    if (semop(semdesk, sopS, 1) == -1)
    {
        perror("Semop error");
        exit(-55);
    }

    for(;;)
    {
        if (semop(semdesk, sop1, 2) == -1)
        {
            perror("Semop error");
            exit(-44);
        }

        shmptr = (char *)shmat(shmdesk, 0, 0);

        if (shmptr == ((char *)-1))
        {
            perror("Shmat error");
            exit(30);
        }
        op1 = (double *)shmptr;
        opt = (char *)(op1 + sizeof(double));
        op2 = (double *)(opt + sizeof(char));

        if (*opt == '+')
            *op1 = *op1 + *op2;
        else if (*opt == '*')
            *op1 = *op1 * *op2;
        else if (*opt == '-')
            *op1 = *op1 - *op2;
        else if (*opt == '/')
            *op1 = *op1 / *op2;

        if (shmdt(shmptr) == -1)
        {
            perror("Shmdt error(1)");
            exit(24);
        }

        if (semop(semdesk, sop2, 2) == -1)
        {
            perror("Semop error");
            exit(13);
        }
        if (semop(semdesk, sop3, 2) == -1)
        {
            perror("Semop error");
            exit(34);
        }
        sleep(1);
    }
}