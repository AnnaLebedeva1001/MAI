#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <cstring>
#include <sys/ipc.h>
#include <sys/msg.h>

using namespace std;

struct Cell
{
    double real;
    double imag;
};

struct Mbuf
{
    long mtype;
    Cell answer[3];
    int child_pid;
    int ratio[4];
};

int method_kardano(double A, double B, double C, double D, struct Cell *x)
{
    double p, q, S, F, temp1, temp2;
    int i;
    if (A == 0)
    {
        perror("X is any\n");
        return -1;
    }

    p = (3.0 * A * C - B * B) / (3.0 * A * A);
    q = (2.0 * B * B * B - 9.0 * A * B * C + 27.0 * A * A * D) / (27.0 * A * A * A);
    S = (q * q / 4.0) + (p * p * p / 27.0);

    if (q == 0)
        F = M_PI / 2.0;
    if (q < 0)
        F = atan(-2.0 * sqrt(-S) / q);
    if (q > 0)
        F = atan(-2.0 * sqrt(-S) / q) + M_PI;

    for (i = 0; i < 3; i++)
        x[i].real = x[i].imag = 0;
    if (S < 0)
    {
        x[0].real = 2.0 * sqrt(-p / 3.0) * cos(F / 3.0) - B / (3.0 * A);
        x[1].real = 2.0 * sqrt(-p / 3.0) * cos((F / 3.0) + 2.0 * M_PI / 3.0) - B / (3.0 * A);
        x[2].real = 2.0 * sqrt(-p / 3.0) * cos((F / 3.0) + 4.0 * M_PI / 3.0) - B / (3.0 * A);
    }
    if (S == 0)
    {
        x[0].real = 2.0 * pow((-q / 2.0), 1 / 3) - B / (3.0 * A);
        x[1].real = -pow((-q / 2.0), 1 / 3) - B / (3.0 * A);
        x[2].real = -pow((-q / 2.0), 1 / 3) - B / (3.0 * A);
    }
    if (S > 0)
    {
        temp1 = pow((-q / 2.0) + sqrt(S), 1 / 3) + pow((-q / 2.0) - sqrt(S), 1 / 3);
        temp2 = pow((-q / 2.0) + sqrt(S), 1 / 3) - pow((-q / 2.0) - sqrt(S), 1 / 3);
        x[0].real = temp1 - B / (3.0 * A);
        x[1].real = -temp1 / 2.0 - B / (3.0 * A);
        x[1].imag = sqrt(3) * temp2 / 2.0;
        x[2].real = -temp1 / 2.0 - B / (3.0 * A);
        x[2].imag = -sqrt(3) * temp2 / 2.0;
    }
    return 0;
}

int main()
{
    struct Mbuf mobj;
    Cell x[3];
    int pid = getpid(), fd = msgget(2348, IPC_CREAT | 0777);
    while (1)
    {
        if (msgrcv(fd, &mobj, 1024, 15, IPC_NOWAIT | MSG_NOERROR) > 0)
        {
            if (method_kardano(mobj.ratio[0], mobj.ratio[1], mobj.ratio[2], mobj.ratio[3], x) == -1)
            {
                cout << ("Invalid A") << endl;
                break;
            }
            mobj.answer[0] = x[0];
            mobj.answer[1] = x[1];
            mobj.answer[2] = x[2];

            mobj.mtype = mobj.child_pid;
            msgsnd(fd, &mobj, sizeof(mobj.answer) * 2, IPC_NOWAIT);
        }
    }

    msgctl(fd, IPC_RMID, 0);
    return 0;
}