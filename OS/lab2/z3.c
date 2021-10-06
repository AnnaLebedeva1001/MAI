#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *f = open(argv[1], O_WRONLY);
    int len = strlen(argv[2]);
    if (argc != 3)
    {
        printf("3 parameters required\n");
        return -1;
    }
    if (f != NULL)
    {
        while (link(argv[1], argv[2]) == -1)
        {
            perror("link");
            argv[2][len - 5] += 1;
        }
        link(argv[1], argv[2]);
    }
    else
        return 1;
    close(f);
    return 0;
}