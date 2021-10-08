#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char c;
    FILE *f1, *f2, *f3;
    f1 = fopen(argv[1], "r");
    f2 = fopen(argv[2], "r");
    assert(f1 != NULL);
    assert(f2 != NULL);
    f3 = fopen("f3.txt", "w");

    while ((!feof(f1)) && (!feof(f2)))
    {
        while (((c = fgetc(f1)) != EOF) && (!isspace(c)))
        {
            fputc(c, f3);
        }
        fputc(' ', f3);
        while (((c = fgetc(f2)) != EOF) && (!isspace(c)))
        {
            fputc(c, f3);
        }
        fputc(' ', f3);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}
