#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void change_elems(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
int elem_in(int *res, int filled, int elem)
{
    for (int i = 0; i < filled; i++)
    {
        if (res[i] == elem)
            return 1;
    }
    return 0;
}

int main()
{
    int n, m, i, j, *mas, act, *max, *min, *arr;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    mas = malloc(n * sizeof(int));
    arr = malloc(n * sizeof(int));
    printf("Введите диапазон случайных чисел: ");
    scanf("%d", &m);
    printf("Сгенерированный массив:\n");
    for (i = 0; i < n; i++)
    {
        mas[i] = rand() % m;
        printf("%d ", mas[i]);
    }
    putchar('\n');
    printf("Выберите действие с массивом:\n");
    printf("Если хотите поменять местами максимальный и минимальный элементы этого массива нажмите 1\n");
    printf("Если хотите создать новый массив,\nкоторый содержит не повторяющиеся элементы из исходного массива в том же порядке следования нажмите 2\n");
    scanf("%d", &act);

    switch (act)
    {
    case 1:
        max = &mas[0], min = &mas[0];
        for (int i = 1; i < n; i++)
        {
            if (*max < mas[i])
                max = &mas[i];
            if (*min > mas[i])
                min = &mas[i];
        }
        printf("Min: %d Max: %d\n", *min, *max);
        change_elems(min, max);

        for (int i = 0; i < n; i++)
            printf("%d ", mas[i]);
        printf("\n");
        break;

    case 2:
        i = 0, j = 0;
        while (1)
        {
            if (j == n)
                break;
            if (!elem_in(arr, i, mas[j]))
            {
                arr[i] = mas[j];
                i++;
            }
            j++;
        }
        for (int l = 0; l < i; l++)
        {
            printf("%d ", arr[l]);
        }
        printf("\n");
        break;

    default:
        printf("Ошибка!!!\n");
        break;
    }

    free(mas);
    free(arr);
    return 0;
}