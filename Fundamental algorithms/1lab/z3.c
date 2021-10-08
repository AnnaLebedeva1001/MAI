#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char flag;
    FILE *fp, *nfp;
    if (argv[1][0] == '-' || argv[1][0] == '/')
    {
        flag = (argv[1][1] == 'n') ? argv[1][2] : argv[1][1];
        char new_name[150] = "out_";
        //nfp = (argv[1][1] == 'n') ? fopen(argv[3], "w") : fopen( strcat(new_name, argv[2]) , "w");
        if (argv[1][1] == 'n')
            strcpy(new_name, argv[3]);
        else
        {
            strcat(new_name, argv[2]);
        }
        nfp = fopen(new_name, "w");

        if (nfp == NULL)
        {
            printf("error, could not open file\n");
            return -1;
        }
    }
    else
    {
        printf("wrong flag symbol\n");
        return -1;
    }

    fp = fopen(argv[2], "r");
    assert(fp != NULL);
    char input;
    int counter = 0;

    while (!feof(fp))
    {
        input = fgetc(fp);
        switch (flag)
        {
        case 'd':
            if (!isdigit(input) && input != EOF)
            {
                fputc(input, nfp);
            }
            break;
        case 'i':
            if (isalpha(input))
            {
                counter++;
            }
            else if (input == '\n')
            {
                fprintf(nfp, "%d\n", counter);
                counter = 0;
            }
            else if (input == EOF)
            {
                fprintf(nfp, "%d", counter);
            }
            break;
        case 's':
            if (input == '\n')
            {
                fprintf(nfp, "%d\n", counter);
                counter = 0;
            }
            else if (input == EOF)
            {
                fprintf(nfp, "%d", counter);
            }
            else if (!isalnum(input) && !(input == ' '))
            {
                counter++;
            }
            break;
        case 'a':
            if (input == '\n')
                fputc('\n', nfp);
            else if (!isdigit(input) && input != EOF)
                fprintf(nfp, "(%d)", input);
            else if (isdigit(input) && input != EOF)
                fprintf(nfp, "%c", input);
            break;
        }
    }

    printf("The work is done!");
    fclose(fp);
    fclose(nfp);
    return 0;
}