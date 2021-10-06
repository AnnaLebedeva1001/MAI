#include <stdio.h>

int main()
{
    int m, i, j;
    scanf("%d", &m);
    for(i  = 1; i < m; i++)
        for(j = 1; j < m; j++)
            if (i * i + j * j == m)  printf("%d %d \n", i * i, j * j);

    return 0;
}