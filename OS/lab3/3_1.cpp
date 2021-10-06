#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        perror("No arg");
        exit(1);
    }
    int count = atoi(argv[1]);
    while(count)
    {
        count--;
        if(!fork())
        {
            printf("Lebedeva Anna Ilinichna, PID: %ld, PPID: %ld \n", (long)getpid(), (long)getppid());
            break;
        }
    }

    return 0;
}