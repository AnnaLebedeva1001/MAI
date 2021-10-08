#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    int act, count = 0;
    int arr1[128], arr2[64], arr[128];
    int len = 0;
    FILE *f = fopen("f.txt", "r");
    assert(f != NULL); // if
    while (fscanf(f, "%d", arr1 + len) != EOF)
        len++;
    printf("Выберите действие с файлом:\n");
    printf("Если хотите переписать в новый массив числа, стоящие на нечетной позиции нажмите 1\n");
    printf("Если хотите переписать в новый массив четные числа нажмите 2\n");
    scanf("%d", &act);

    switch (act)
    {
    case 1:
        for (int i = 0; i < len / 2; i++)
        {
            arr2[i] = arr1[i * 2 + 1];
            printf("%d ", arr2[i]);
        }
        break;

    case 2:
        for (int i = 0; i < len; i++)
        {
            if (arr1[i] % 2 == 0)
            {
                arr2[count] = arr1[i];
                printf("%d ", arr2[count]);
                count++;
            }
        }
        break;

    default:
        printf("Ошибка!!!\n");
        break;
    }

    fclose(f);
    return 0;
}