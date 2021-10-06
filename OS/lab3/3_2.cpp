#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int count(int level)
{
    int result = 0;
    int tmp = 1;
    for (int n = level; n > 0; n--)
    {
        tmp = tmp * n;
        result += tmp;
    }
    return result;
}

int main()
{
    char to_print[500];
    int i = 0;
    int timer = 15;
    int is_main = 1;
    int init = 5;
    int n = init;
    pid_t fork_pid = fork();

    while (n)
    {
        n--;
        if (!fork())
        {
            i = 0;
            to_print[0] = 0;
            is_main = 0;
            timer--;
            init--;
            n = init;
        }
        else
        {
            i += sprintf(to_print + i, "<child %d>", fork_pid);
        }
    }

    printf("%d : %s\n", getpid(), to_print);

    if (is_main)
    {
        sleep(2);
        system("pstree -p");
        printf("Lebedeva Anna Ilinichna, count %d\n", count(init));
        sleep(timer - 2);
    }
    else
    {
        sleep(timer);
    }

    return 0;
}