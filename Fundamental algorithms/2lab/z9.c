#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>

int len(char *str)
{
    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}

int findDecimalRepr(int c)
{
    c = toupper(c);
    char arr[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 36; i++)
    {
        if (arr[i] == c)
            return i;
    }
}

void shift_left(char *str)
{
    int length = len(str);
    char temp1;
    for (int i = 0; i < length; i++)
    {
        temp1 = *(str + 1);
        *str = temp1;
        str++;
    }
    *str = '\0';
}

void shift(char *str)
{
    int length = len(str);
    char temp1 = *str;
    char temp2;
    *str = '0';
    str++;
    for (int i = 0; i < length; i++)
    {
        temp2 = *str;
        *str = temp1;
        temp1 = temp2;
        str++;
    }
    *str = '\0';
}

void add(int base, char *res, char *num)
{
    char arr[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int lengthNum = len(num);
    int lengthRes = len(res);
    while (lengthRes <= lengthNum)
    {
        shift(res);
        lengthRes = len(res);
    }
    while (*res != '\0')
        res++;
    while (*num != '\0')
        num++;
    num--;
    res--;
    int remember = 0;
    for (int i = 0; (i < lengthNum); i++)
    {
        if (findDecimalRepr(*num) >= base)
        { 
            printf("Цифра не может быть больше системы счисления\n");
            exit(1);
        }
        int sum = findDecimalRepr(*num) + findDecimalRepr(*res) + remember;
        if (sum >= base)
            remember = 1;
        else
            remember = 0;
        *res = arr[sum % base];
        res--;
        num--;
    }
    while (remember)
    {
        int sum = findDecimalRepr(*res) + remember;
        if (sum >= base)
            remember = 1;
        else
            remember = 0;
        *res = arr[sum % base];
        res--;
    }
    res++;
}

void sum(char *res, int base, int argc, ...)
{
    va_list ap;
    va_start(ap, argc);
    res[0] = '0';
    res[1] = '\0';
    for (int i = 0; i < argc; i++)
    {
        add(base, res, va_arg(ap, char *));
    }
    while (res[0] == '0')
        shift_left(res);
    va_end(ap);
}

int main()
{
    char res[80];
    sum(res, 21, 2, "21M", "21");
    printf("%s\n", res);
    return 0;
}
