#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
int compare_mail(int, int);

struct Adress
{
    char* city = (char*)malloc(SIZE * sizeof(char));
	char* street = (char*)malloc(SIZE * sizeof(char));
    unsigned int house;
    unsigned int apartment;
    unsigned int index;
};

struct Mail
{
    struct Adress adress1;
    double parcel_weight;
    int mail_id;
};

struct Post
{
    struct Adress* adress_post = (struct Adress*)malloc(sizeof(struct Adress));
	struct Mail* mail = (struct Mail*)malloc(SIZE * sizeof(struct Mail));
};

struct Mail add_mail()
{
	struct Mail mails;

	printf("Напишите город: ");
	scanf("%s", mails.adress1.city);
	printf("Напишите улицу: ");
	scanf("%s", mails.adress1.street);
	printf("Напишите дом: ");
	scanf("%s", &mails.adress1.house);
	printf("Напишите квартиру: ");
	scanf("%d", &mails.adress1.apartment);
	printf("Напишите индекс: ");
	scanf("%d", &mails.adress1.index);
	printf("Напишите вес посылки: ");
	scanf("%lf", &mails.parcel_weight);
	printf("Напишите индентификатор: ");
	scanf("%d", &mails.mail_id);
	return mails;
}

struct Mail *delete_mail(struct Mail *mail, int count)
{
    int old_count, index;
	old_count = count;
	count--;
	index = 0;
	printf("Напишите индекс: ");
	scanf("%d", &index);

	for (count; count > -1; count--) 
		if (mail[count].adress1.index == index)
			break;

	if (count == -1)
		printf("Нет получателя с таким индексом\n\n");
	else {
		for (count; count < old_count; count++) 
			if (count + 1 != old_count)
				mail[count] = mail[count + 1];
			else {
				mail[count].adress1.city = NULL;
				mail[count].adress1.street = NULL;
				mail[count].adress1.house = 0;
				mail[count].adress1.apartment = 0;
				mail[count].adress1.index = 0;
				mail[count].parcel_weight = 0;
				mail[count].mail_id = 0;
			}
	}

	return mail;
}

void search_by_id(struct Post post, int k)
{
    int i, id;
	i = 0;
	id = 0;

	printf("Напишите индентификатор посылки которую хотите найти: ");
	scanf("%d", &id);
	putchar('\n');
	if (k == 0) 
		perror("Ошибка!!!\n");
	else 
		for (i; i < k; i++)
			if (post.mail[i].mail_id == id)
				printf("%d. %s, %s, %d, кв. %d, индекс %d, вес %lf, идентификатор - %d\n", i + 1, post.mail[i].adress1.city, post.mail[i].adress1.street,
					post.mail[i].adress1.house, post.mail[i].adress1.apartment, post.mail[i].adress1.index, post.mail[i].parcel_weight, post.mail[i].mail_id);
	putchar('\n');
}

int compare_mail(int a, int b)
{
    return (a - b);
}

int compare_index(const void* a, const void* b)
{
	if (((struct Mail*)a)->adress1.index - ((struct Mail*)b)->adress1.index == 0)
		return compare_mail(((struct Mail*)a)->mail_id, ((struct Mail*)b)->mail_id);
	else
		return (((struct Mail*)a)->adress1.index - ((struct Mail*)b)->adress1.index);
}

void show_all(struct Post post, int n)
{
	int i;
	i = 0;
	if (n == 0)
		perror("Ошибка!!!\n");
	else
		for (i; i < n; i++)
			printf("%d. %s, %s, %d, кв. %d, инд. %d, вес %lf, идентификатор = %d\n", i + 1, post.mail[i].adress1.city, post.mail[i].adress1.street,
				post.mail[i].adress1.house, post.mail[i].adress1.apartment, post.mail[i].adress1.index, post.mail[i].parcel_weight, post.mail[i].mail_id);
	putchar('\n');
}

int main()
{
    struct Post post;
    struct Adress adress_post;
    printf("Напишите адрес почтового отделения(город, улицу, дом, квартиру и индекс):\n");
    scanf("%s %s %d %d %d", adress_post.city, adress_post.street, &adress_post.house,
          &adress_post.apartment, &adress_post.index);
    post.adress_post = &adress_post;
    int act, i = 0, index, id;
    printf("Если хотите начать работу, нажмите 0\n");
    scanf("%d", &act);
    while (1)
    {
        switch (act)
        {
        case 0:
            printf("Если хотите добавить письмо или посылку, нажмите 1\n");
            printf("Если хотите удалить письмо или посылку, нажмите 2\n");
            printf("Если хотите найти письмо или посылку по идентификатору, нажмите 3\n");
            printf("Если хотите отсортировать письма или посылки по индексу получателя, а потом по их идентификатору нажмите 4\n");
            printf("Если хотите , посмотреть все письма и посылки, нажмите 5\n");
            printf("Если хотите завершить работу, нажмите 6\n");
            scanf("%d", &act);
            break;

        case 1:
            post.mail[i] = add_mail();
            i++;
            act = 0;
            break;

        case 2:
            post.mail = delete_mail(post.mail, i);
			if (post.mail[i - 1].adress1.city == NULL)
				i--;
            act = 0;
            break;

        case 3:
            search_by_id(post, i);
            act = 0;
            break;

        case 4:
            qsort(post.mail, i, sizeof(struct Mail), compare_index);
            act = 0;
            break;

        case 5:
            show_all(post, i);
            act = 0;
			break;

        case 6:
            printf("Работа завершена\n");
            exit(0);
            break;

        default:
            perror("Ошибка!!!\n");
			exit(-1);
            break;
        }
    }
    return 0;
}
