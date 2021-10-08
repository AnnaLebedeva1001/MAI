#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    unsigned int id;
    char name[20];
    char surname[20];
    unsigned int salary;
};

int number_of_lines(FILE *fp)
{
    int n = 0, i;
    while ((i = fgetc(fp)) != EOF)
    {
        if (i == '\n')
            ++n;
    }
    fseek(fp, 0, SEEK_SET);
    return n;
}

int ascending(struct Employee *ptr, int n)
{
    struct Employee buf;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (ptr[j].salary > ptr[j + 1].salary)
            {
                buf = ptr[j + 1];
                ptr[j + 1] = ptr[j];
                ptr[j] = buf;
            }
        }
    }
    return 0;
}

int descending(struct Employee *ptr, int n)
{
    struct Employee buf;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (ptr[j].salary < ptr[j + 1].salary)
            {
                buf = ptr[j + 1];
                ptr[j + 1] = ptr[j];
                ptr[j] = buf;
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int n, k;
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("error, could not open file\n");
        return -1;
    }
    FILE *nfp = fopen("nfp.txt", "w");
    if (nfp == NULL)
    {
        printf("error, could not open file\n");
        return -1;
    }

    n = number_of_lines(fp);
    struct Employee *employee = (struct Employee *)malloc(n * sizeof(struct Employee));

    printf("%d people in the file stored\n", n);

    for (k = 0; k < n; k++)
    {
        fscanf(fp, "%d %s %s %d\n", &employee[k].id, employee[k].name, employee[k].surname, &employee[k].salary);
        printf("%d %s %s %d \n", employee[k].id, employee[k].name, employee[k].surname, employee[k].salary);
    }

    if (argv[2][0] == '-' || argv[2][0] == '/')
    {
        switch (argv[2][1])
        {
        case 'a':
            ascending(employee, n);
            for (k = 0; k < n; k++)
                fprintf(nfp, "%d %s %s %d \n", employee[k].id, employee[k].name, employee[k].surname, employee[k].salary);
            break;
        case 'b':
            descending(employee, n);
            for (k = 0; k < n; k++)
                fprintf(nfp, "%d %s %s %d \n", employee[k].id, employee[k].name, employee[k].surname, employee[k].salary);
            break;
        default:
            printf("wrong flag symbol\n");
            break;
        }
    }

    printf("The work is done!\n");
    fclose(fp);
    fclose(nfp);
    free(employee);
    return 0;
}