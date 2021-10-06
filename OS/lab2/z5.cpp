#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

struct File
{
    char *name;
    time_t ctime;
};

typedef int (*Comparer)(struct File *first, struct File *second);

int compare_by_ctime(struct File *first, struct File *second)
{
    if (first->ctime == second->ctime)
    {
        return 0;
    }
    else if (first->ctime < second->ctime)
    {
        return -1;
    }
    return 1;
}

void sort(struct File *file, size_t count, Comparer comparer)
{
    int i, j, comparisonResult;
    struct File temp;
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            comparisonResult = comparer(file + i, file + j);
            if (comparisonResult == 1)
            {
                temp = *(file + i);
                *(file + i) = *(file + j);
                file[j] = temp;
            }
        }
    }
}

int number_of_files(DIR *dir, char *dirname)
{
    if ((dir = opendir(dirname)) == NULL)
    {
        printf("Can't open folder\n");
        return -1;
    }
    int n = 0;
    struct dirent *f_cur;
    while ((f_cur = readdir(dir)) != NULL)
        n++;
    closedir(dir);
    return n;
}

void print_struct_file(struct File *file, size_t count)
{
    int k;
    for (k = 0; k < count; k++)
    {
        printf("%s %d\n", file[k].name, file[k].ctime);
    }
}

int main(int argc, char *argv[])
//argv[1] - директория
{
    if (argc != 2)
        return -1;
    else
    {
        DIR *dir;
        int n = number_of_files(dir, argv[1]), i;
        if ((dir = opendir(argv[1])) == NULL)
            return -1;
        else
        {
            int i;
            struct stat buf;
            struct dirent *f_cur;
            struct File *file = (struct File *)malloc(n * sizeof(struct File));

            printf("Фалы в директории:\n");
            i = 0;
            while ((f_cur = readdir(dir)) != NULL && i < n)
            {
                lstat(f_cur->d_name, &buf);
                file[i].ctime = buf.st_ctime;
                file[i].name = f_cur->d_name;
                printf("%s %d\n", file[i].name, file[i].ctime);
                ++i;
            }
            sort(file, n, compare_by_ctime);
            printf("\nОтсортированные файлы по времени последнего изменения:\n");
            print_struct_file(file, n);
            closedir(dir);
            free(file);
            return 0;
        }
    }
}