#include <stdio.h>
#include <dirent.h>

int main()
{
    printf("Enter directory name: ");
    char dirname[30];
    scanf("%s", dirname);
    DIR *dir = opendir(dirname);
    if (dir == NULL)
    {
        printf("Can't open folder\n");
        closedir(dir);
        return -1;
    }
    else
    {
        DIR *tmp;
        struct dirent *f_cur;
        while (f_cur = readdir(dir))
        {
            if ((tmp = opendir(f_cur->d_name)) == NULL)
                printf("%s\n", f_cur->d_name);
            else
                closedir(tmp);
        }
        if (closedir(dir) == -1)
            printf("Error closing directory!\n");
        printf("Done...\n");
        return 0;
    }
}