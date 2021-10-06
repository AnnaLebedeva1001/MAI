#include <stdlib.h>
#include <stdio.h>

int main()
{
    int a = 0, b = 1, i = -1, n;
    scanf("%d", &n);
    while(a < n)
    {
        i++;
        b = a + b;
        a = b - a;
    }
    if (a == n)
    {
        b = a + b;
        a = b - a;
        i++;
    }
    printf("№%d; число Фибоначи: %d\n", i+1, a);
    return 0;
}