#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[])
//argv[1] - директория
{
    if (argc != 2)
    {
        printf("2 parameters required\n");
        return -1;
    }
    else
    {
        DIR *dir;
        if ((dir = opendir(argv[1])) == NULL)
        {
            printf("Can\'t open folder\n");
            return -1;
        }
        else
        {
            struct dirent *f_cur;
            while ((f_cur = readdir(dir)) != NULL)
            {
                printf("%s\n", f_cur->d_name);
            }
            printf("Done...\n");
            closedir(dir);
            return 0;
        }
    }
}