#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 20
int compare_email_id(int, int);

struct Adress {
	char* city = (char*)malloc(N * sizeof(char));
	char* street = (char*)malloc(N * sizeof(char));
	char* house = (char*)malloc(N * sizeof(char));
	int flat;
	int index;
};

struct Mail {
	struct Adress adress_recipient;
	double weight;
	int email_id;
};

struct Post {
	struct Adress* adress_post = (struct Adress*)malloc(sizeof(struct Adress));
	struct Mail* mail = (struct Mail*)malloc(N * sizeof(struct Mail));
};

int compare_index(const void* a, const void* b)
{
	if (((struct Mail*)a)->adress_recipient.index - ((struct Mail*)b)->adress_recipient.index == 0)
		return compare_email_id(((struct Mail*)a)->email_id, ((struct Mail*)b)->email_id);
	else
		return (((struct Mail*)a)->adress_recipient.index - ((struct Mail*)b)->adress_recipient.index);
}

int compare_email_id(int a, int b)
{
	return (a - b);
}

struct Mail add_recipient()
{
	struct Mail a;

	printf("Enter city: ");
	scanf("%s", a.adress_recipient.city);
	printf("Enter street: ");
	scanf("%s", a.adress_recipient.street);
	printf("Enter house: ");
	scanf("%s", a.adress_recipient.house);
	printf("Enter flat: ");
	scanf("%d", &a.adress_recipient.flat);
	printf("Enter index: ");
	scanf("%d", &a.adress_recipient.index);
	printf("Enter weight of package: ");
	scanf("%lf", &a.weight);
	printf("Enter email ID: ");
	scanf("%d", &a.email_id);
	printf("The recipient was successfully added!\n\n");

	return a;
}

struct Mail* delete_recipient(struct Mail* a, int kol_mail)
{
	int old_kol_mail, index;
	old_kol_mail = kol_mail;
	kol_mail--;
	index = 0;
	printf("Enter the index of the recipient you want to delete: ");
	scanf("%d", &index);

	for (kol_mail; kol_mail > -1; kol_mail--) 
		if (a[kol_mail].adress_recipient.index == index)
			break;

	if (kol_mail == -1)
		printf("Didn't find those recipient\n\n");
	else {
		for (kol_mail; kol_mail < old_kol_mail; kol_mail++) 
			if (kol_mail + 1 != old_kol_mail)
				a[kol_mail] = a[kol_mail + 1];
			else {
				a[kol_mail].adress_recipient.city = NULL;
				a[kol_mail].adress_recipient.street = NULL;
				a[kol_mail].adress_recipient.house = NULL;
				a[kol_mail].adress_recipient.flat = 0;
				a[kol_mail].adress_recipient.index = 0;
				a[kol_mail].weight = 0;
				a[kol_mail].email_id = 0;
			}
		printf("The recipient was successfully deleted!\n\n");
	}

	return a;
}

void show_all(struct Post post, int kol_mail)
{
	int i;
	i = 0;
	if (kol_mail == 0)
		printf("Noone\n");
	else
		for (i; i < kol_mail; i++)
			printf("%d. %s, %s, %s, fl. %d, in. %d, wght. %lf, ID = %d\n", i + 1, post.mail[i].adress_recipient.city, post.mail[i].adress_recipient.street,
				post.mail[i].adress_recipient.house, post.mail[i].adress_recipient.flat, post.mail[i].adress_recipient.index, post.mail[i].weight, post.mail[i].email_id);
	putchar('\n');
}

void find_by_email_id(struct Post post, int kol_mail)
{
	int i, id;
	i = 0;
	id = 0;

	printf("Enter the email Id of the recipient you want to search: ");
	scanf("%d", &id);
	putchar('\n');
	if (kol_mail == 0) //то есть никого не было
		printf("Noone\n");
	else 
		for (i; i < kol_mail; i++)
			if (post.mail[i].email_id == id)
				printf("%d. %s, %s, %s, fl. %d, in. %d, wght. %lf, ID = %d\n", i + 1, post.mail[i].adress_recipient.city, post.mail[i].adress_recipient.street,
					post.mail[i].adress_recipient.house, post.mail[i].adress_recipient.flat, post.mail[i].adress_recipient.index, post.mail[i].weight, post.mail[i].email_id);
	putchar('\n');
}

void start(struct Post post)
{
	int marker, i;
	marker = 0;
	i = 0; //количество объектов post.mail

	while (marker != 6) {
		printf("What would you like:\n");
		printf("1. Add recipient\n");
		printf("2. Delete recipient\n");
		printf("3. Find by email ID\n");
		printf("4. Sort Mail\n");
		printf("5. Show all\n");
		printf("6. Exit\n");
		printf("Enter the action: ");
		scanf("%d", &marker);
		putchar('\n');
		if (marker < 1 || marker > 6) {
			printf("Invalid value of the action, please try again...\n");
			continue;
		}
		else if (marker == 1) {
			post.mail[i++] = add_recipient();
		}
		else if (marker == 2) {
			post.mail = delete_recipient(post.mail, i);
			if (post.mail[i - 1].adress_recipient.city == NULL) //если удалили уменьшаем массив 
				i--;
		}
		else if (marker == 3) {
			find_by_email_id(post, i);
		}
		else if (marker == 4) {
			qsort(post.mail, i, sizeof(struct Mail), compare_index);
			printf("Successfully sorted!\n\n");
		}
		else if (marker == 5) {
			show_all(post, i);
		}
		else
			printf("Goodbye!\n");
	}
}

struct Post add_post()
{
	struct Post post;
	struct Adress adress_post;
	printf("Enter the address of the current post office\n");
	printf("Enter city: ");
	if(scanf("%s", adress_post.city));
	printf("Enter street: ");
	if(scanf("%s", adress_post.street));
	printf("Enter house: ");
	if(scanf("%s", adress_post.house));
	printf("Enter flat: ");
	if(scanf("%d", &adress_post.flat));
	printf("Enter index: ");
	if(scanf("%d", &adress_post.index));
	printf("-------------------------\n");
	post.adress_post = &adress_post;
	return post;
}

int main()
{
	struct Post post; //задаем адрес текущего почтового отделения 
	post = add_post();
	printf("Hello, welcome to the post office at %s, %s, %s, fl. %d, in. %d\n\n", post.adress_post->city,
		post.adress_post->street, post.adress_post->house, post.adress_post->flat, post.adress_post->index);
	start(post); //стартуем
	return 0;
}