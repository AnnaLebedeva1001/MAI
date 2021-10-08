#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 32

char *to_base(unsigned int n, unsigned int r)
{
    const unsigned int base = 1U << r;
    unsigned int rem = 0;
    char *res = (char *)malloc(SIZE * sizeof(char));
    int i = SIZE - 1;
    while (n != 0)
    {
        rem = n & (base - 1);
        if (rem > 9)
        {
            for (int j = 0; j < 9; j++)
                rem = ~-rem;
            res[i] = 64 | rem;
        }
        else
            res[i] = 48 | rem;
        i--;
        n = n >> r;
    }
    if (n == 0) res[i] = 48;
    return res;
}

void print_and_free_res(char *res)
{
    for (int i = 0; i < SIZE; i++)
        printf("%c", res[i]);
    free(res);
}

int main()
{
    int number, r, i, power;
    printf("Число в 10-ной системе счисления: ");
    scanf("%u", &number);
    printf("Для возведения в 2^r напишите r: ");
    scanf("%d", &r);
    power = pow(2, r);
    printf("Число в %d-ой системе счисления: ", power);
    print_and_free_res(to_base(number, r));
    putchar('\n');
    return 0;
}