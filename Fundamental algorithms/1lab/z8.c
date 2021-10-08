#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    int mas[n];
    printf("Сгенерированный массив:\n");
    for (i = 0; i < n; ++i)
    {
        mas[i] = rand() % 100;
        printf("%d ", mas[i]);
    }

    printf("\n");

    int max = 0, min = 0, k;

    for (i = 0; i < n; i++)
    {
        if (mas[i] < mas[min])
            min = i;
        if (mas[i] > mas[max])
            max = i;
    }

    printf("Минимальный элемент %d\nМаксимальный элемент %d\n", mas[min], mas[max]);

    k = mas[min];
    mas[min] = mas[max];
    mas[max] = k;

    printf("Новый массив: ");
    for (i = 0; i < n; ++i)
        printf("%d ", mas[i]);

    printf("\n");

    return 0;
}