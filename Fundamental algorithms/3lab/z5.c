#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number_of_lines(FILE *fp)
{
    int n = 0, i;
    while ((i = fgetc(fp)) != EOF)
    {
        if (i == '\n')
            ++n;
    }
    fseek(fp, 0, SEEK_SET);
    return n;
}

struct Student
{
    unsigned int id;
    char name[20];
    char surname[20];
    unsigned int group;
    unsigned int marks[5];
};

typedef int (*Comparer)(struct Student *first, struct Student *second);

int compare_by_id(struct Student *first, struct Student *second)
{
    if (first->id == second->id)
    {
        return 0;
    }
    else if (first->id < second->id)
    {
        return -1;
    }
    return 1;
}

int compare_by_group(struct Student *first, struct Student *second)
{
    if (first->group == second->group)
    {
        return 0;
    }
    else if (first->group < second->group)
    {
        return -1;
    }
    return 1;
}

int compare_by_name(struct Student *first, struct Student *second)
{
    int comparisonResult = strcmp(first->name, second->name);
    if (!comparisonResult)
    {
        return 0;
    }
    else if (comparisonResult < 0)
    {
        return -1;
    }
    return 1;
}

int compare_by_surname(struct Student *first, struct Student *second)
{
    int comparisonResult = strcmp(first->surname, second->surname);
    if (!comparisonResult)
    {
        return 0;
    }
    else if (comparisonResult < 0)
    {
        return -1;
    }
    return 1;
}

void sort(struct Student *values, size_t count, Comparer comparer)
{
    int i, j, comparisonResult;
    struct Student temp;
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            comparisonResult = comparer(values + i, values + j);
            if (comparisonResult == 1)
            {
                temp = *(values + i);
                *(values + i) = *(values + j);
                values[j] = temp;
            }
        }
    }
}

void print_struct_student(struct Student *student, size_t count)
{
    int k;
    for (k = 0; k < count; k++)
    {
        printf("%d %s %s %d %d %d %d %d %d\n", student[k].id, student[k].name, student[k].surname,
               student[k].group, student[k].marks[0], student[k].marks[1],
               student[k].marks[2], student[k].marks[3], student[k].marks[4]);
    }
}

int main(int argc, char *argv[])
{
    int n, k, i, j;
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("error, could not open file\n");
        return -1;
    }
    FILE *fp = fopen("score.txt", "w");
    double score = 0, average_student_score[5], group_average_score = 0;

    n = number_of_lines(f);
    struct Student *student = (struct Student *)malloc(n * sizeof(struct Student));

    for (k = 0; k < n; k++)
    {
        fscanf(f, "%d %s %s %d %d %d %d %d %d\n", &student[k].id, student[k].name, student[k].surname, &student[k].group, &student[k].marks[0], &student[k].marks[1], &student[k].marks[2], &student[k].marks[3], &student[k].marks[4]);
        printf("%d %s %s %d %d %d %d %d %d\n", student[k].id, student[k].name, student[k].surname, student[k].group, student[k].marks[0], student[k].marks[1], student[k].marks[2], student[k].marks[3], student[k].marks[4]);
    }

    printf("\n Сортировка по имени: \n");
    sort(student, n, compare_by_name);
    print_struct_student(student, n);

    printf("\n Сортировка по фамилии: \n");
    sort(student, n, compare_by_surname);
    print_struct_student(student, n);

    printf("\n Сортировка по группе: \n");
    sort(student, n, compare_by_group);
    print_struct_student(student, n);

    printf("\n Сортировка по id: \n");
    sort(student, n, compare_by_id);
    print_struct_student(student, n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 5; j++)
        {
            score += student[i].marks[j];
        }
        group_average_score += score;
        average_student_score[i] = score / 5;
        fprintf(fp, "%d %s %s %d %.1f\n", student[i].id, student[i].name, student[i].surname, student[i].group, average_student_score[i]);
        score = 0;
    }
    group_average_score /= (n * 5);

    printf("\nСтуденты, чей бал за экзамены выше среднего:\n");
    for (i = 0; i < n; i++)
    {
        if (average_student_score[i] > group_average_score)
            printf("%s %s\n", student[i].name, student[i].surname);
    }

    printf("The work is done!\n");
    fclose(f);
    fclose(fp);
    free(student);
    return 0;
}