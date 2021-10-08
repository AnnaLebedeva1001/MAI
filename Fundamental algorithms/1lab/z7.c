#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	char ch, c, digit = 'A';
	int n = 1, base = 0, digitValue, res = 0;
	char buf[BUFSIZ], *b = buf;
	FILE* f1, * f2;
	if (argc != 3) {
		printf("Input 2 file's names!");
		exit(-4);
	}
	f1 = fopen(argv[1], "r");
	f2 = fopen(argv[2], "w");



	if (f1 == NULL) {
		printf("Can't open first file!\n");
		exit(-1);
	}
	if (f2 == NULL) {
		printf("Can't open second file!\n");
		exit(-2);
	}

	do {

		while (((ch = fgetc(f1)) != EOF) && (!isspace(ch))) {
			if ((isdigit(ch))) {
				digitValue = ch - '0';
				*b++ = ch;
			}
			else if (isalpha(ch)) {
				digitValue = toupper(ch) - 'A' + 10;
				*b++ = ch;
			}
			if (digitValue > base - 1) {
				base = digitValue + 1;
			}

		}
		if (b == buf)
		{
			continue;
		}
		*b = 0; // '\0'
		b = buf;
		res = 0;
		while (*b)
		{
			res = res * base + (isdigit(*b) ? *b++ - '0' : toupper(*b++) - 'A' + 10);
		}
		b = buf;
		fprintf(f2, "%s(%d) = %d(10)", buf, base, res);


		memset(buf, 0, BUFSIZ); // зануление массива (optional)
		base = 0;
		fputc('\n', f2);

	} while (!feof(f1));

	printf("Second file has changed!\n");
	fclose(f1);
	fclose(f2);
	return 0;
}