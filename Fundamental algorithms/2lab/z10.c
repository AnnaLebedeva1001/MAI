#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

int len(char *str)
{
    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}

int is_finite(char *res, int base, double n)
{
    char arr[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int PREC = 10;
    char num[PREC + 2];
    char firstnum[PREC + 2];
    num[0] = 0 + '0';
    firstnum[0] = 0 + '0';
    num[PREC + 1] = '\0';
    firstnum[PREC + 1] = '\0';

    for (int i = 1; i < PREC + 1; i++)
    {
        n *= 10;
        int wholepart = (int)n;
        if ((int)(n + 0.0001) == wholepart + 1)
            wholepart++;
        n -= wholepart;
        num[i] = wholepart + '0';
        firstnum[i] = wholepart + '0';
    }
    int FINITE = -1;
    while (1)
    {
        int wholepart = 0;
        for (int j = PREC; j > 0; j--)
        {
            int digit = num[j] - '0';
            digit = digit * base + wholepart;
            wholepart = 0;
            while (digit >= 10)
            {
                wholepart++;
                digit -= 10;
            }
            num[j] = digit + '0';
        }
        *res = arr[wholepart];
        res++;
        FINITE = 1;
        for (int i = 1; i < PREC; i++)
        {
            if (num[i] - '0' != 0)
            {
                FINITE = -1;
                break;
            }
        }
        if (FINITE == 1)
            break;
        FINITE = 0;
        for (int i = 1; i < PREC; i++)
        {
            if (firstnum[i] != num[i])
            {
                FINITE = -1;
                break;
            }
        }
        if (FINITE == 0)
            break;
    }
    *res = '\0';
    return FINITE;
}

void finite_repr(int base, int n, ...)
{
    va_list ap;
    va_start(ap, n);
    double num;
    char result[80];
    int finite;
    for (int i = 0; i < n; i++)
    {
        num = va_arg(ap, double);
        finite = is_finite(result, base, num);
        if (finite == 1)
        {
            printf("%f in base-%d is 0.%s - FINITE\n", num, base, result);
        }
        else if (finite == 0)
        {
            printf("%f in base-%d is 0.(%s) - INFINITE\n", num, base, result);
        }
    }

    va_end(ap);
}

int main()
{
    finite_repr(6, 3, 0.8, 0.99, 0.723);
    return 0;
}