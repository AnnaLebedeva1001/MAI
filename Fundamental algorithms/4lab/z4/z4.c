#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _NAME 20

struct Node
{
	char name[_NAME];
	char surname[_NAME];
	char patronymic[_NAME];
	char borntime[_NAME];
	char gender[_NAME];
	double salary;
	struct Node* next;
};

struct List
{
	struct Node* root;
};

void AddbyPrior(struct List* list, struct Node* el)
{
	struct Node** it;
	for (it = &list->root; *it != NULL && strcmp(el->borntime , (*it)->borntime)>=0; it = &((*it)->next));
	el->next = (*it);
	(*it) = el;
}

void Printlist(struct List* list, FILE* outfile)
{
	struct Node* it;
	for (it = list->root; it != NULL; it = it->next)
	{
		fprintf(outfile,"name: %s ", it->name);
		fprintf(outfile, "%s ", it->surname);
		fprintf(outfile, "%s\t ", it->patronymic);
		fprintf(outfile, " borntime: %s\t ", it->borntime);
		fprintf(outfile, "gender: %s\t", it->gender);
		fprintf(outfile, "salary: %f\n", it->salary);
	}
}

struct Node* searchbyname(char* sname, char* ssurname, struct List* list)
{
	struct Node* it;
	for (it = list->root; it != NULL; it = it->next)
	{
		if (strcmp(sname, it->name) == 0 && strcmp(ssurname, it->surname) == 0)
        {
			break;
		}
	}
	return it;
}

struct Node* Delfirstel(struct List* list)
{
	if (list->root == NULL)
    {
		printf("list IS EMPTY");
		return NULL;
	}
	struct Node* it;
	it = list->root;
	list->root = list->root->next;
	return it;
}

void PrintNode(struct Node* person)
{
	printf("name: %s ", person->name);
	printf("%s ", person->surname);
	printf("%s ", person->patronymic);
	printf("borntime: %s ", person->borntime);
	printf( "gender: %s ", person->gender);
	printf ("salary: %f\n", person->salary);
}

int main()
{
    struct List* mylist = (struct List*)calloc(1, sizeof(struct List));
    struct Node* newperson;
    struct Node* person;
    struct Node* find;
    char name[_NAME], surname[_NAME], line[BUFSIZ], filename[_NAME];
    int flag;
    printf("enter filename\n");
    scanf("%s", filename);
    FILE* infile = fopen(filename, "r");
    FILE* outfile = fopen("/home/anna/projects/3sem/FundAlg/4lab/z4/outfile.txt", "w");
    if (infile == NULL) 
    {
        printf("file is not found\n");
        return -1;
    }
    while (!feof(infile))
    {
        fgets(line, BUFSIZ, infile);
        person = (struct Node*)malloc(sizeof(struct Node));
        strcpy(person->name, strtok(line, " "));
        strcpy(person->surname, strtok(NULL, " "));
        strcpy(person->patronymic, strtok(NULL, " "));
        strcpy(person->borntime, strtok(NULL, " "));
        strcpy(person->gender, strtok(NULL, " "));
        person->salary = atof(strtok(NULL, " "));
        AddbyPrior(mylist, person);
    }
    while(1) 
    {
        printf("ENTER 1 to find person by name and surname\n");
        printf("ENTER 2 to add person\n");
        printf("ENTER 3 to del person\n" );
        printf("ENTER 4 to upload data to a file\n");
        printf("ENTER 5 to stop the program\n");
        scanf("%d", &flag);
        switch (flag)
        {
            case 1:
                printf("enter name\n");
                scanf("%s", name);
                printf("enter surname\n");
                scanf("%s", surname);
                find = searchbyname(name, surname, mylist);
                if (find == NULL)
                {
                    printf("not found\n");
                    break;
                }
                PrintNode(find);
                break;
            case 2:
                newperson= (struct Node*)malloc(sizeof(struct Node));
                printf("enter name\n");
                scanf("%s", &newperson->name);
                printf("enter surname\n");
                scanf("%s", &newperson->surname);
                printf("enter patronymic \n");
                scanf("%s", &newperson->patronymic);
                printf("enter borntime\n");
                scanf("%s", &newperson->borntime);
                printf("enter gender\n");
                scanf("%s", &newperson->gender);
                printf("enter salary\n");
                scanf("%lf", &newperson->salary);
                AddbyPrior(mylist, newperson);
                break;
            case 3:
                Delfirstel(mylist);
                break;
            case 4:
                Printlist(mylist, outfile);
                break;
            case 5:
                printf("program was finished\n");
                fclose(infile);
                fclose(outfile);
                exit(0);
            default:
                printf("wrong flag\n");
                break;
        }
    }
    return 0;
}
