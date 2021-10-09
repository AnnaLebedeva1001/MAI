#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define RING struct ring

RING
{
char name[15]; // название города
RING* next,* prev;
};

void insert(RING** start, string st)
{
	RING* new_n;
	new_n = (RING*)malloc(sizeof(RING));
	new_n->name[0] = '\0';
	strcpy(new_n->name, st.c_str());
	if (*start)
	{
		new_n->next = (*start)->next;
		new_n->prev = *start;
		(*start)->next->prev = new_n;
		(*start)->next = new_n;
	}
	else
	{
		new_n->prev = new_n;
		new_n->next = new_n;
	}
	*start = new_n;
}

int dir_path(RING* start, string s1, string s2, int L)
{
	int er1 = 0, er2 = 0, j1 = 0, j2 = 0, d = 0;
	int status = 1;
	RING* tek = start;
	do
	{
		tek = tek->next;
		if (strcmp(tek->name, s1.c_str()) == 0)
			do
			{
				tek = tek->next;
				j1 += 1;
				er1 = (strcmp(tek->name, s1.c_str()) == 0) ? 1 : 0;
				d = ((2 * j1) < L) ? 1 : 0;
			} while ((strcmp(tek->name, s1.c_str()) != 0) && (strcmp(tek->name, s2.c_str()) != 0));
		else if (strcmp(tek->name, s2.c_str()) == 0)
			do
			{
				tek = tek->next;
				j2 += 1;
				er2 = (strcmp(tek->name, s2.c_str()) == 0) ? 1 : 0;
				d = ((2 * j2) > L) ? 1 : 0;
			} while ((strcmp(tek->name, s1.c_str()) != 0) && (strcmp(tek->name, s2.c_str()) != 0));
	} while ((tek != start) && (strcmp(tek->name, s1.c_str()) != 0) && (strcmp(tek->name, s2.c_str()) != 0));
	if (er1 || er2)
	{
		if (er1)
			cout << "Ошибка в названии начального пункта" << endl;
		else
			cout << "Ошибка в названии конечного пункта" << endl;
		exit(status - '1');
	}
	if (j1 + j2 == 0)
	{
		cout << "Ошибка в названиях городов" << endl;
		exit(status - '1');
	}
	return d;
}

void writePath(RING* start, int dir, string s1, string s2)
{
	RING* tek = start;
	cout << "Кратчайший путь:" << endl;
	while (strcmp(tek->name, s1.c_str()) != 0)
		tek = tek->next;
	do
	{
		puts(tek->name);
		if (dir)
			tek = tek->next;
		else
			tek = tek->prev;
	} while (strcmp(tek->name, s2.c_str()) != 0);
	puts(tek->name);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int j, len = 0;
	string st1, st2;
	RING* r1 = NULL;
	cout << "Введите 7 городов кольцевого маршрута: " << endl;
	for (j = 1; j <= 7; j++)
	{
		cout << "город №" << j << ": ";
		cin >> st1;
		insert(&r1, st1);
		len++;
	}
	cout << "Задайте начальный и конечный пункты: ";
	cin >> st1;
	cin >> st2;
	writePath(r1, dir_path(r1, st1, st2, len), st1, st2);
	return 0;
}
