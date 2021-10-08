#include <stdio.h>
#include <stdarg.h>

int finding_substring(char *str, char *substr)
{
    int len = strlen(substr);
    char *ref = substr;
    while (*str && *ref)
    {
        if (*str++ == *ref)
        {
            ref++;
        }
        if (!*ref)
        {
            return (str - len);
        }
        if (len == (ref - substr))
        {
            ref = substr;
        }
    }
    return NULL;
}

int search(char *substr, ...)
{
    va_list args;
    char *str[BUFSIZ];
    FILE *f;
    char *filename;
    va_start(args, str);
    filename = va_arg(args, char *);
    while ((f = fopen(filename, "r")) != NULL)
    {
        printf("%s\n", filename);
        int line = 1;
        while (fgets(str, sizeof(str), f) != NULL)
        {
            while (1)
            {
                if (finding_substring(str, substr) != NULL)
                {
                    printf("Подстрока %s в строке %d\n", substr, line);
                    line = 1;
                    break;
                }
                else
                {
                    printf("В строке %d нет подстроки %s!!!\n", line, substr);
                    break;
                }
            }
            line++;
        }
        fclose(f);
        filename = va_arg(args, char *);
    }
    va_end(args);
}

int main()
{
    search("Hello", "f61.txt", "f62.txt");
    return 0;
}