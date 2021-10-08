#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#define str_SIZE 150

int mod(int x, int y)
{
    return x % y >= 0 ? x % y : x % y + y;
}

int main()
{
    char c[str_SIZE][3][str_SIZE];
    char str[str_SIZE];
    FILE *f = fopen("f.txt", "r");
    FILE *nf = fopen("nf.txt", "w");
    assert(f != NULL);
    assert(nf != NULL);
    int n = 0;
    while (fgets(str, str_SIZE, f))
    {
        sscanf(str, "%s %s %s", c[n][0], c[n][1], c[n][2]);
        ++n;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            fprintf(nf, "%s ", c[i][mod(j - 1, 3)]);
        fprintf(nf, "\n");
    }

    fclose(f);
    fclose(nf);
    return 0;
}