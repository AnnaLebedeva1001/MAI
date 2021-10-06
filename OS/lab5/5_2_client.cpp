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
    int ratio[4] = {0, 0, 0, 0};
};

int main()
{
  int a, b, c, d, i, len, select;
  int mypid = getpid();
  struct Mbuf mobj;
  int fd = msgget(2348, 0);

  for(;;)
  {
    cout << "Enter ratio of cubic equation (A,B,C,D: Ax + By + Cz + D = 0)" << endl;
    cin >> a >> b >> c >> d;
    mobj.ratio[0] = a;
    mobj.ratio[1] = b;
    mobj.ratio[2] = c;
    mobj.ratio[3] = d;

    mobj.child_pid = mypid;
    mobj.mtype = 15;

    len = sizeof(mobj.answer);
    msgsnd(fd, &mobj, 1024, IPC_NOWAIT);
    sleep(1);
    if (msgrcv(fd, &mobj, 1024, mypid, IPC_NOWAIT | MSG_NOERROR) > 0)
    {
      for (i = 0; i < 3; i++)
      {
        if (mobj.answer[i].imag == 0.0)
          printf("x%d = %.15lf\n", i, mobj.answer[i].real);
        else
          printf("x%d = %.15lf + i * %.15lf\n", i, mobj.answer[i].real, mobj.answer[i].imag);
      }
    }

    break;
  }

  return 0;
}
