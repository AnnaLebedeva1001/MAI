#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int conversion_to_number(char s[])
{
	int i, n;
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
		n = 10 * n + (s[i] - '0');
	return n;
}

int main(int argc, char *argv[])
{
	int number, n, m, cnt = 0;
	long long int s;
	char *flag;
	if (argc < 3)
	{
		printf("Неверное количество аргументов!");
		exit(-1);
	}
	number = conversion_to_number(argv[1]); //лучше использовать atoi
	flag = argv[2];

	if (number > 0 && (flag[0] == '/' || flag[0] == '-'))
	{
		switch (flag[1])
		{
		case 'h':
			for (int n = number; n <= 100; n += number, ++m)
				printf("%d\n", n);
			if (m == 0)
				printf("Число больше 100\n");
			break;

		case 'p':
			for (n = 2; n <= number / 2; n = n + 1)
			{
				m = number % n;
				if (m == 0)
					break;
			}
			if (n > number / 2)
				printf("Число простое \n");
			else
				printf("Число составное \n");
			break;

		case 's':
			while (number > 0)
			{
				n = number % 10;
				printf("%d ", n);
				number /= 10;
			}
			printf("\n");
			break;

		case 'e':
			if (number <= 10)
			{
				for (int n = 1; n <= 10; n++)
				{
					for (int m = 1; m <= number; m++)
					{
						s = pow(n, m);
						printf("%llu ", s);
					}
					printf("\n");
				}
				printf("\n");
			}
			else
				printf("Число не подходит\n");
			break;

		case 'a':
			n = number * (number + 1) / 2;
			printf("%d\n", n);
			break;

		case 'f':
			n = 1;
			for (m = 1; m <= number; m++)
				n *= m;
			printf("%d\n", n);
			break;
		default:
			printf("Неверный флаг!\n");
			break;
		}
	}

	return 0;
}