#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *flag;
    flag = argv[1];
    char *c;
    c = (int *)malloc((argc - 2) * sizeof(int));
    int x1, x2, D;
    for (int i = 2; i < argc; i++)
    {
        c[i] = atoi(argv[i]);
    }
    if (flag[0] == '/' || flag[0] == '-')
    {
        switch (flag[1])
        {
        case 'q':
            D = c[3] * c[3] - 4 * c[2] * c[4];
            if (D > 0)
            {
                x1 = (-c[3] + sqrt(D)) / (2 * c[2]);
                x2 = (-c[3] - sqrt(D)) / (2 * c[2]);
                printf("x1 = %d\nx2 = %d\n", x1, x2);
            }
            if (D < 0)
            {
                printf("Корней нет\n");
            }
            if (D == 0)
            {
                x1 = -(-c[3]) / (2 * c[2]);
                printf("x1 = x2 = %d\n", x1);
            }
            break;
        case 'm':
            if (c[2] > 0 && c[3] > 0)
            {
                if (c[2] % c[3] == 0 || c[3] % c[2] == 0)
                    printf("%d и %d кратны\n", c[2], c[3]);
                else
                    printf("%d и %d не кратны\n", c[2], c[3]);
            }
            else
                printf("Числа введены не вернро\n");
            break;
        case 't':
            c[2] *= c[2];
            c[3] *= c[3];
            c[4] *= c[4];
            if ((c[2] == c[3] + c[4]) || (c[3] == c[2] + c[4]) || (c[4] == c[3] + c[2]))
                printf("Это прямоугольный треугольник\n");
            else
                printf("Не прямоугольный треугольник\n");
            break;
        }
    }
    return 0;
}