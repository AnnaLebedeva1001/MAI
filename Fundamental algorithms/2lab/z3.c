#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int length(char *str)
{
    int l = 0;
    while (*str != '\0')
    {
        l++;
        str++;
    }
    return l;
}

void *str_rev(char *str)
{
    char *beg = str;
    str = beg + length(beg);
    //while (*str != '\0')
        //str++;
    char *end = --str;
    char temp;
    while (beg < end)
    {
        temp = *end;
        *end = *beg;
        *beg = temp;
        beg++;
        end--;
    }
}

void transform1(char *s)
{
    int i = 0;
    //длина, сдвигаться на два, зафиксировать начало, пока \0 -
    while (*s != '\0')
    {
        if (i % 2 == 0)
            *s = toupper(*s);
        i++;
        s++;
    }
}

void transform2(char *str)
{
    char temp[80];
    int i = 0;
    int flag = 0;
    int length = 0;

    while (1)
    {
        if (*str == '\0')
        {
            flag++;
            str -= length;
        }

        if (!flag)
            length++;

        if (flag > 2)
            break;

        if (flag == 0 && isdigit(*str))
        {
            temp[i] = *str;
            i++;
        }
        else if (flag == 1 && isalpha(*str))
        {
            temp[i] = *str;
            i++;
        }
        else if (flag == 2 && !isalnum(*str))
        {
            temp[i] = *str;
            i++;
        }
        str++;
    }

    i = 0;

    while (*str != '\0')
    {
        *str = temp[i];
        i++;
        str++;
    }
}

char *concat(char *dst, char *src)
{
    dst += length(dst);
    while (*src != '\0')
    {
        *dst++ = *src++;
    }
    *dst = '\0';
    return dst;
}

int main(int argc, char *argv[])
{
    char *str0, *flag, *str;
    flag = argv[2];
    str = argv[1];
    if (argc == 4)
        str0 = argv[3];
    if (flag[0] == '-')
    {
        switch (flag[1])
        {
        case 'l':
            printf("Длина: %d\n", length(str));
            break;
        case 'r':
            str_rev(str);
            printf("%s\n", str);
            break;
        case 'u':
            transform1(str);
            printf("%s\n", str);
            break;
        case 'n':
            transform2(str);
            printf("%s\n", str);
            break;
        case 'c':
            concat(str, str0);
            printf("%s\n", str);
            break;
        default:
            break;
        }
    }

    printf("The work is done!\n");
    return 0;
}