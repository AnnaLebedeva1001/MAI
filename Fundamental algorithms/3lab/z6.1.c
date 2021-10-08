#include <stdio.h>
#include <stdlib.h>

#define String struct string
String
{
    char *arr;
    unsigned int str_len;
};

char *mystrcpy(char *str1, char *str2);

String string_creation(char *str, String Str)
{
    Str.str_len = strlen(str) + 1;
    Str.arr = (char *)malloc(sizeof(char) * Str.str_len);
    mystrcpy(Str.arr, str);
    return Str;
}

void delete_line(String str)
{
    free(str.arr);
    str.str_len = 0;
}

int mystrcmp(char *str1, char *str2)
{
    while ('\0' != *str1 && *str1 == *str2)
    {
        str1++;
        str2++;
    }
    int result = *str2 - *str1;
    return result;
}

char *mystrcpy(char *str1, char *str2)
{
    if (str1 == NULL)
        return NULL;
    char *ptr = str1;
    while (*str2 != '\0')
    {
        *str1++ = *str2++;
    }
    *str1 = '\0';
    return ptr;
}

char *my_strcat(char *dest, const char *src)
{
    char *ptr = dest;
    while (*dest)
        dest++;
    while (*dest++ = *src++);
    return ptr;
}

char *mystrdup(char *old_str, int i)
{
    int STR_SIZE = (i - 1) * 2 + 1;
    char *str = (char *)malloc(sizeof(char) * STR_SIZE);
    str[STR_SIZE] = '\0';
    for (int j = 0; j < i - 1; j++)
    {
        str[j] = old_str[j];
        str[j + i - 1] = old_str[j];
    }
    return str;
}

int main()
{
    String s1, s2;
    char str1[BUFSIZ], str2[BUFSIZ];
    printf("Введите строку 1: ");
    scanf("%s", str1);
    s1 = string_creation(str1, s1);
    printf("Введите строку 2: ");
    scanf("%s", str2);
    s2 = string_creation(str2, s2);
    if (mystrcmp(s1.arr, s2.arr) == 0)
        printf("Строки идентичны!!\n");
    else
        printf("Эти строки различны!!\n");
    delete_line(s1);
    printf("Скопированная строка: %s\n", mystrcpy(s1.arr, s2.arr));
    printf("Конкатенация: %s\n", my_strcat(s1.arr, s2.arr));
    printf("Дублирование: %s\n", mystrdup(s2.arr, s2.str_len));
    return 0;
}