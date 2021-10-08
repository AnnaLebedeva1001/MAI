#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 33

int main(int argc, char *argv[])
{
	int base, i = 0, max = 0, res = 0;
	char num[SIZE], maxnum[SIZE], str[SIZE];
	printf("Enter base: ");
	scanf("%d", &base);
	printf("Enter numbers:");
	while (strcmp(num, "Stop"))
	{
		scanf("%s", num);
		char *pc = num - 1;
		res = 0;
		while (*++pc)
		{
			if ((isdigit(*pc) && (*pc - '0' >= base) || isalpha(*pc) && *pc - 'A' + 10 >= base) && strcmp(num, "Stop"))
			{
				printf("Invalid number: %c", *pc);
				exit(-1);
			}
			res = res * base + (isdigit(*pc) ? *pc - '0' : *pc - 'A' + 10);
		}
		if (res > max && strcmp(num, "Stop"))
		{
			max = res;
			strcpy(maxnum, num);
		}
	}
	printf("Max number (%d system): %s\n", base, maxnum);
	printf("Max number (decimal system): %d\n", max);

	for (i = 9; i <= 36; i += 9)
	{
		int r;
		base = i;
		int tmp = max;
		int j = 0;
		
		while (tmp)
		{
			r = tmp % base;
			str[j++] = (r > 9) ? (r - 10 + 'A') : (r + '0');
			tmp /= base;
		}

		printf("%d system:", base);
		int k;
		for (k = j - 1; k >= 0; k--)
		{
			printf("%c", str[k]);
		}
		printf("\n");
	}

	return 0;
}