#include <stdio.h>
#include <math.h>
double eps = 0.000000001;

double f(double x)
{
    return sin(x) + 2 * pow(x, 2) - 3;
}

double Dhtm(double f(double), double a, double b)
{
    double c;
    while (fabs(b - a) > eps)
    {
        c = (a + b) / 2;
        if (f(c) * f(a) > 0)
            a = c;
        else
            b = c;
    }
    return c;
}

int main()
{
    printf("x = %lf\n", Dhtm(f, 1, 2));
    return 0;
}
