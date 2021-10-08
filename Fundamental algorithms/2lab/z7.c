#include <stdio.h>
#include <stdarg.h>
#include <math.h>

void is_convex(int LEN, ...)
{
    if (LEN < 3)
    {
        printf("Error\n");
        return;
    }
    va_list ap;
    int coords[2][LEN];
    va_start(ap, LEN);
    for (int i = 0; i < LEN; i++)
    {
        coords[0][i] = va_arg(ap, int);
        coords[1][i] = va_arg(ap, int);
        printf("X: %d Y: %d\n", coords[0][i], coords[1][i]);
    }
    int Q = 1;
    int T = coords[0][LEN - 1] * coords[1][0] - coords[0][0] * coords[1][LEN - 1];
    int Z = T / fabs(T);
    int P = 1;
    int i = 1;
    while (i < LEN - 1 && Q)
    {
        T = coords[0][i] * coords[1][i + 1] - coords[0][i + 1] * coords[1][i];
        P = P * Z * T / fabs(T);
        if (P < 0)
            Q = 0;
        i++;
    }
    if (Q)
        printf("CONVEX\n");
    else
        printf("NOT CONVEX\n");
    va_end(ap);
}

double solve(int x, int n, ...)
{
    va_list ap;
    double result = 0;
    va_start(ap, n);
    int arg;
    for (int i = n; i >= 0; i--)
    {
        arg = va_arg(ap, int);
        result += pow(x, i) * arg;
    }
    va_end(ap);
    return result;
}

int main()
{
    is_convex(6, 0, 0, 0, 1, 1, 2, 2, 0, 1, -2, -2, -1);
    is_convex(6, 0, 0, 0, 1, 2, 2, 3, 0, 2, -2, 1, -2);
    printf("%f\n", solve(2, 2, 2, 2, 2));
    return 0;
}