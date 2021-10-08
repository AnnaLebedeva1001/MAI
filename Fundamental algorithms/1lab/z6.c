#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char flag;
    FILE *fp, *nfp;
    fp = fopen(argv[1], "r");
    nfp = fopen(argv[2], "w");
    assert(fp != NULL);
    assert(nfp != NULL);
    int n = 1;
    char c;

    while (!feof(fp))
    {
        while (((c = fgetc(fp)) != EOF) && (!isspace(c)))
        {
            if ((n % 2 == 0) && isupper(c))
                fprintf(nfp, "%c", tolower(c));
            else if (n % 5 == 0)
                fprintf(nfp, "%d", c);
            else
                fputc(c, nfp);
        }
        fputc(' ', nfp);
        n++;
    }
    fclose(fp);
    fclose(nfp);
    return 0;
}