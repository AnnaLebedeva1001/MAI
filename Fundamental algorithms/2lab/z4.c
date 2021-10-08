#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double geometric_mean(int argc, ...)
{
    if (argc <= 0)
        return 0;
    double result = 1;
    va_list numlist;

    va_start(numlist, argc);

    for (int i = 0; i < argc; i++)
    {
        result *= va_arg(numlist, int);
    }

    va_end(numlist);

    return pow(result, (double)1 / argc);
}

double pow0(double i, int j)
{
    if (j == 0)
        return 1;
    if (j < 0)
    {
        j *= -1;
        return 1 / (i * pow0(i, j - 1));
    }
    if (j == 1)
        return i;
    else
        return i * pow0(i, j - 1);
}

int main()
{
    printf("%1.5f\n", geometric_mean(2, 2, 2));
    printf("%1.5f\n", pow0(2, 4));
    printf("%1.5f\n", pow0(2, -3));
    return 0;
}