#include <iostream>
#include <limits.h>

using namespace std;

long long int power(long long int num, long long int step)
{
	long long int res = 1;
	for (int i = 0; i < step; i++)
		res = res * num;

	return res;
}

int main()
{
	long long int n, i = 1;
	long long int marker = 1;
	cout << "Напишите число: ";
	cin >> n;
	int a_1 = 0;
	short int a_2 = 1;
	unsigned short int a_3 = 1;
	unsigned short int a_3_pred = 0;
	long long int a_4 = 1;
	unsigned char a_5 = 1;
	unsigned char a_5_pred = 0;


	setlocale (LC_ALL, "RUSSIAN");

	if (n < 0)
	{
		cout << "Введите полоительное число!" << endl;
		exit(1);
	}

	for (i; i < n + 1; i++)
		a_1 = a_1 + i * i;

	cout << "Число = " << n << endl << "Сумма = " << a_1 << endl;

	a_1 = 1;
	i = 0;
	while (a_1 > 0)
	{
		a_1 = marker;
		i++;
		marker = marker + power(i, i);
	}
	cout << "Переполнение INT начиная с n = "<< i - 1 << endl;

	i = 0;
	marker = 1;
	while (a_2 > 0)
	{
		a_2 = marker;
		i++;
		marker = marker + power(i, i);
	}
	cout << "Переполнение SHORT INT начиная с n = " << i - 1 << endl;

	i = 0;
	marker = 1;
	while (a_4 > 0)
	{
		a_4 = marker;
		i++;
		marker = marker + power(i, i);
	}
	cout << "Переполнение LONG INT начиная с n = " << i - 1<< endl;

	i = 0;
	marker = 1;
	while (a_3 >= a_3_pred)
	{
		a_3_pred = a_3;
		a_3 = marker;
		i++;
		marker = marker + power(i, i);
	}
	cout << "Переполнение WORD начиная с n = " << i - 1 << endl;

	i = 0;
	marker = 1;
	while (a_5 >= a_5_pred)
	{
		a_5_pred = a_5;
		a_5 = marker;
		i++;
		marker = marker + power(i, i);
	}
	cout << "Переполнение BYTE начиная с n = " << i - 1 << endl;

	return 0;
}