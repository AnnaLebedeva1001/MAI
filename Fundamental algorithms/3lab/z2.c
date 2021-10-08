#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define size 20
#define NUMBER_IS_NOT_VALID -1

int *search_one(int k, int l)
{
    int count = 0, i = 0, rem, n, num = 1 << (k - 1), last_num = 1 << k; //1<<(k-1)
    int *res = (int *)malloc(size * sizeof(int));
    if (k <= 0 || l <= 0 || l > k)
    {
        perror("Не делайте так больше, пожалуйста!!\n");
        exit(NUMBER_IS_NOT_VALID);
    }
    for (num; num < last_num; num++)
    {
        n = num;
        while (num != 0)
        {
            rem = num & 1;
            if (rem == 1)
                count++;
            num >>= 1;
        }
        if (count == l)
        {
            res[i] = n;
            i++;
        }
        num = n;
        count = 0;
    }
    return res;
}

int *finding_duplicate_one(int k, int l)
{
    int count = 0, i = 0, rem, bit_count, n, num = 1 << (k - 1), last_num = 1 << k;
    int *res = (int *)malloc(size * sizeof(int));
    if (k <= 0 || l <= 0 || l > k)
    {
        perror("Не делайте так больше, пожалуйста!!\n");
        exit(NUMBER_IS_NOT_VALID);
    }
    for (num; num < last_num; num++)
    {
        n = num;
        while (num != 0)
        {
            rem = num & 1;
            if (rem == 1)
            {
                count++;
            }
            else
            {
                if (count == l) break;
                count = 0;
            }
            num >>= 1;
        }
        if (count == l)
        {
            res[i] = n;
            i++;
        }
        num = n;
        count = 0;
    }
    return res;
}

void print_and_free_res(int *res)
{
    for (int i = 0; i < size; i++)
    {
        if (res[i] == 0)
            break;
        printf("%d ", res[i]);
    }
    printf("\n");
    free(res);
}

int main()
{
    int k, l, num;
    printf("Напишите количество бит: ");
    scanf("%d", &k);
    printf("Напишите количество единиц: ");
    scanf("%d", &l);
    if (l > k)
    {
        perror("Количество единиц должно быть меньше количества бит!!!!\n");
        exit(-1);
    }
    printf("Числа, содержащие %d бит и ровно %d единиц:\n", k, l);
    print_and_free_res(search_one(k, l));
    printf("Числа, содержащие %d бит и ровно %d подряд идущих единиц:\n", k, l);
    print_and_free_res(finding_duplicate_one(k, l));
    return 0;
}