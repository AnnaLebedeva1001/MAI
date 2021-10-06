#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n,s;
    printf("Ведите число для возведения в третью степень: ");
    scanf("%d", &n);
    int i = n * (n - 1) + 1, a = 1;
    printf("%d^3 = %d", n, i);
    s=i;
    do
    {
        printf("+");
        a++;
        i += 2;
        s+=i;
        printf("%d", i);
    } while(a != n);

    printf(" = %d", s);

    return 0;
}