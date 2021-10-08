#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 50

struct Message
{
    unsigned int id;
    char *message_text;
    unsigned int len_byte;
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        perror("error\n");
        return -1;
    }
    char *str = (char *)malloc(N * sizeof(char)), buf[N], *filename = argv[2], *stop = argv[1];
    int id = 0, n = 0, k, len, i = 0;
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        perror("error, could not open file\n");
        return -1;
    }

    struct Message message;

    while (1)
    {
        printf("Enter your message: ");
        fgets(str, N, stdin);
        message.id = id++;
        len = strlen(str);
        str[len - 1] = '\0';
        if (strcmp(str, stop) == 0)
            break;
        message.message_text = (char *)malloc(len * sizeof(char));
        strcpy(message.message_text, str);
        message.len_byte = len;
        fprintf(f, "%d-%s-%d\n", message.id, message.message_text, message.len_byte);
        free(message.message_text);
        n++;
    }
    fclose(f);
    f = fopen(filename, "r");
    if (f == NULL)
    {
        perror("error, could not open file\n");
        return -1;
    }

    struct Message *messages = (struct Message *)malloc(n * sizeof(struct Message));

    printf("%d messages\n", n);

    for (k = 0; k < n; k++)
    {
        i = 0;
        messages[k].id = 0;
        messages[k].len_byte = 0;
        fgets(str, N, f);
        while (*str != '-')
        {
            messages[k].id = messages[k].id * 10 + (*str++) - '0';
        }
        *str++;
        while (*str != '-')
        {
            buf[i] = *str++;
            i++;
        }
        *str++;
        while (*str != '\n')
        {
            messages[k].len_byte = messages[k].len_byte * 10 + (*str++) - '0';
        }
        *str = '\0';
        messages[k].message_text = (char *)malloc(messages[k].len_byte * sizeof(char));
        strcpy(messages[k].message_text, buf);
        printf("%d %s %d\n", messages[k].id, messages[k].message_text, messages[k].len_byte);
        free(messages[k].message_text);
    }

    printf("The work is done!\n");
    fclose(f);
    return 0;
}