#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 20

struct Bool
{
	char letter;
	int num_letter;
};

int function_change_int(char *a)
{
	int i, number;

	if (a == NULL)
		return -1;

	number = a[0] - '0';
	i = 1;
	while (a[i] != '\0')
	{
		number = number * 10 + (a[i] - '0');
		i++;
	}
	return number;
}

int changer_to_10(char *a, int s_s)
{
	int i, number;
	number = 0;
	i = 0;
	if (a)
	{
		if ((tolower(a[0]) >= 'a') && (tolower(a[0]) <= 'z'))
			number = (tolower(a[0]) - 'a' + 10) * s_s;
		else if ((a[0] >= '0') && (a[0] <= '9'))
			number = (a[0] - '0') * s_s;
		else
			number = 0;
		i = 1;

		if (a[i] == '\0')
		{
			if ((tolower(a[0]) >= 'a') && (tolower(a[0]) <= 'z'))
				return tolower(a[0]) - 'a' + 10;
			else if ((a[0] >= '0') && (a[0] <= '9'))
				return a[0] - '0';
		}

		while (a[i] != '\0')
		{
			if (a[i + 1] == '\0')
			{
				if ((tolower(a[i]) >= 'a') && (tolower(a[i]) <= 'z'))
					number = number + tolower(a[i]) - 'a' + 10;
				else if ((a[i] >= '0') && (a[i] <= '9'))
					number = number + a[i] - '0';
			}
			else
			{
				if ((tolower(a[i]) >= 'a') && (tolower(a[i]) <= 'z'))
					number = (number + tolower(a[i]) - 'a' + 10) * s_s;
				else if ((a[i] >= '0') && (a[i] <= '9'))
					number = (number + a[i] - '0') * s_s;
			}
			i++;
		}
	}

	return number;
}

char *function_change_to_ss(int number, int ss) // number - число в 10 сс, ss - система счисления в котрую нужно перевести
{
	char *str;
	char *temp;
	int kol, i;
	i = 0;
	kol = 3;
	str = (char *)calloc(kol, sizeof(char));

	if (number < 0)
	{
		number = number * (-1);
		if (str)
			str[i] = 0;
		i++;
		kol++;
		temp = (char *)realloc(str, kol * sizeof(char));
		if (temp)
			str = temp;
	}

	if (number / ss == 0)
	{
		if (str)
		{
			if (number % ss <= 9)
				str[i] = number + '0';
			else
				str[i] = number + 'A' - 10;
			str[i + 1] = '\0';
		}

		return str;
	}

	while (number != 0)
	{
		if (str)
		{
			if (number % ss <= 9)
				str[i] = number % ss + '0';
			else
				str[i] = number % ss + 'A' - 10;
		}
		i++;
		kol++;
		temp = (char *)realloc(str, kol * sizeof(char));
		if (temp)
			str = temp;
		number = number / ss;
	}

	// осталось перевернуть массив
	i = i - 1;
	char *str_new;
	int j;
	j = 0;
	str_new = (char *)calloc(i + (unsigned int)(3.0), sizeof(char));

	if (str)
		if (str[0] == 0)
		{
			if (str_new)
				str_new[j] = 0;
			j++;
		}

	while (i != -1)
		if (str_new && str)
		{
			str_new[j] = str[i];
			i--;
			j++;
		}

	if (str_new)
		str_new[j] = '\0';

	return str_new;
}

struct Bool *check_for_read(struct Bool *a, char *str, int kol_a, char *base, FILE *trass, int trass_marker)
{
	struct Bool letter;
	char *variable = (char *)malloc(N * sizeof(char));
	char symbol;
	int i, j, res, int_base;
	i = 0;
	j = 0;
	res = 0;
	int_base = 0;
	base[j] = '\0';

	if (str[i++] == 'r' && str[i++] == 'e' && str[i++] == 'a' && str[i++] == 'd' && str[i++] == '(')
	{
		if (str[i] >= 'a' && str[i++] <= 'z')
			symbol = str[i - 1];
		else
		{
			if (trass_marker == 1)
				fprintf(trass, "%s - Invalid syntax: argument 1 not char\n", str);
			printf("Invalid syntax: argument 1 not char\n");
			exit(1);
		}
		if (str[i] == ',')
			i++;
		else
		{
			if (trass_marker == 1)
				fprintf(trass, "%s - Invalid value of char\n", str);
			printf("Invalid value of char\n");
			exit(1);
		}
		while (str[i] != ')')
		{
			if (str)
			{
				if (str[i] == '\0')
				{
					if (trass_marker == 1)
						fprintf(trass, "%s - Invalid syntax: not )\n", str);
					printf("Invalid syntax: not )\n");
					exit(1);
				}
				if (str[i] >= 'a' && str[i] <= 'z')
				{
					if (trass_marker == 1)
						fprintf(trass, "%s - Ivalid value of base\n", str);
					printf("Ivalid value of base\n");
					exit(1);
				}
				base[j++] = str[i++];
				base[j] = '\0';
			}
		}
		if (base[0] == '\0')
		{ //ничего не добавилось
			if (trass_marker == 1)
				fprintf(trass, "%s - Invalid syntax: not base\n", str);
			printf("Invalid syntax: not base\n");
			exit(1);
		}
		else
		{
			if (str[++i] == '\0')
			{
				int_base = function_change_int(base);
				if (int_base <= 1)
				{
					if (trass_marker == 1)
						fprintf(trass, "%s - Invalid value of base\n", str);
					printf("Invalid value of base\n");
					exit(1);
				}
				printf("Enter variable of %c: ", symbol);
				scanf("%s", variable);
				i = 0;
				while (variable[i++] != '\0')
					if (tolower(variable[i - 1]) >= 'a' && tolower(variable[i - 1]) <= 'z')
					{
						if (tolower(variable[i - 1]) - 'a' + 10 >= int_base)
						{
							if (trass_marker == 1)
								fprintf(trass, "%s - Invalid value: variable not exist in this base\n", str);
							printf("Invalid value: variable not exist in this base\n");
							exit(1);
						}
					}
					else if (variable[i - 1] >= '0' && variable[i - 1] <= '9')
					{
						if (variable[i - 1] - '0' >= int_base)
						{
							if (trass_marker == 1)
								fprintf(trass, "%s - Invalid valure: variable not exist in this base\n", str);
							printf("Invalid valure: variable not exist in this base\n");
							exit(1);
						}
					}
					else
					{
						if (trass_marker == 1)
							fprintf(trass, "%s - Invalid value of variable\n", str);
						printf("Invalid value of variable\n");
						exit(1);
					}
			}
			else
			{
				if (trass_marker == 1)
					fprintf(trass, "%s - Invalid syntax: after last symbol ) not end of str\n", str);
				printf("Invalid syntax: after last symbol ) not end of str\n");
				exit(1);
			}
		}
		res = changer_to_10(variable, int_base);
		i = 0;
		if (kol_a == 0)
		{
			letter.letter = symbol;
			letter.num_letter = res;
			a[0] = letter;
			return a;
		}
		else
		{
			for (i; i < kol_a; i++) //проверяем есть ли такая буква
				if (a[i].letter == symbol)
				{
					letter.letter = symbol;
					letter.num_letter = res;
					a[i] = letter;
					a[kol_a].letter = NULL;
					return a;
				}
			letter.letter = symbol;
			letter.num_letter = res;
			a[kol_a] = letter;
			return a;
		}
	}
	else
	{
		if (trass_marker == 1)
			fprintf(trass, "%s - Ivalid syntax: not function read\n", str);
		printf("Ivalid syntax: not function read\n");
		exit(1);
	}
	free(variable);
}

void check_for_write(struct Bool *a, char *str, int kol_a, char *base, FILE *trass, int trass_marker)
{
	char *res_char = (char *)malloc(N * sizeof(char));
	char symbol;
	int i, j, int_base, marker;
	i = 0;
	j = 0;
	int_base = 0;
	marker = -1;
	symbol = NULL;

	if (str[i++] == 'w' && str[i++] == 'r' && str[i++] == 'i' && str[i++] == 't' && str[i++] == 'e' && str[i++] == '(')
	{
		if (str[i] >= 'a' && str[i++] <= 'z')
			symbol = str[i - 1];
		else
		{
			if (trass_marker == 1)
				fprintf(trass, "%s - Invalid syntax: argument 1 not char\n", str);
			printf("Invalid syntax: argument 1 not char\n");
			exit(1);
		}
		if (str[i] == ',')
			i++;
		else
		{
			if (trass_marker == 1)
				fprintf(trass, "%s - Invalid value of char\n", str);
			printf("Invalid value of char\n");
			exit(1);
		}
		while (str[i] != ')')
		{
			if (str)
			{
				if (str[i] == '\0')
				{
					if (trass_marker == 1)
						fprintf(trass, "%s - Invalid syntax: not )\n", str);
					printf("Invalid syntax: not )\n");
					exit(1);
				}
				if (str[i] >= 'a' && str[i] <= 'z')
				{
					if (trass_marker == 1)
						fprintf(trass, "%s - Ivalid value of base\n", str);
					printf("Ivalid value of base\n");
					exit(1);
				}
				base[j++] = str[i++];
				base[j] = '\0';
			}
		}
		if (base[0] == '\0')
		{ //ничего не добавилось
			if (trass_marker == 1)
				fprintf(trass, "%s - Invalid syntax: not base\n", str);
			printf("Invalid syntax: not base\n");
			exit(1);
		}
		else
		{
			if (str[++i] == '\0')
			{
				int_base = function_change_int(base);
				if (int_base <= 1)
				{
					if (trass_marker == 1)
						fprintf(trass, "%s - Invalid value of base\n", str);
					printf("Invalid value of base\n");
					exit(1);
				}
				i = 0;
				for (i; i < kol_a; i++)
					if (a[i].letter == symbol)
						marker = i;
				if (marker == -1)
				{
					if (trass_marker == 1)
						fprintf(trass, "%s - Invalid value: uninitialized variable %c\n", str, symbol);
					printf("Invalid value: uninitialized variable %c\n", symbol);
					exit(1);
				}
				else
				{
					res_char = function_change_to_ss(a[marker].num_letter, int_base);
					printf("Result of %c = %d in ss = %d: %s\n", symbol, a[marker].num_letter, int_base, res_char);
					if (trass_marker == 1)
						fprintf(trass, "%s completed successfully, result of %c = %d in ss = %d: %s\n", str, symbol, a[marker].num_letter, int_base, res_char);
				}
			}
			else
			{
				if (trass_marker == 1)
					fprintf(trass, "%s - Invalid syntax: after last symbol ) not end of str\n", str);
				printf("Invalid syntax: after last symbol ) not end of str\n");
				exit(1);
			}
		}
	}
	else
	{
		if (trass_marker == 1)
			fprintf(trass, "%s - Invalid syntax: not function write\n", str);
		printf("Invalid syntax: not function write\n");
		exit(1);
	}
	free(res_char);
}

int check_letter(struct Bool *a, char symbol, int kol_a)
{
	int marker, i;
	marker = -1;
	i = 0;

	for (i; i < kol_a; i++)
		if (a[i].letter == symbol)
			marker = i;

	if (marker == -1)
		return -1;
	else
		return marker;
}

int is_implication(char *str, int i) 
{
	return str[i] == '&' && (str[i + 1] >= 'a' && str[i + 1] <= 'z') && str[i + 2] == '\0';
}

int operation(struct Bool result, char *str, struct Bool *a, int kol_a, FILE *trass, int trass_marker)
{
	int i, marker, res;
	i = 4;
	marker = -1;
	res = 0;

	if (str[i] == '+' && str[i + 1] == '>' && (str[i + 2] >= 'a' && str[i + 2] <= 'z') && str[i + 3] == '\0')
	{
		marker = check_letter(a, str[i + 2], kol_a);
		if (marker == -1)
		{
			if (trass_marker == 1)
				fprintf(trass, "%s - Invalid value: uninitialized variable %c\n", str, str[i + 2]);
			printf("Invalid value: uninitialized variable %c\n", str[i + 2]);
			exit(1);
		}
		else
		{
			res = a[marker].num_letter;
			res = ~(~result.num_letter | res);
		}
	}
	else if (str[i] == '+' && (str[i + 1] >= 'a' && str[i + 1] <= 'z') && str[i + 2] == '\0')
	{
		marker = check_letter(a, str[i + 1], kol_a);
		if (marker == -1)
		{
			if (trass_marker == 1)
				fprintf(trass, "%s - Invalid value: uninitialized variable %c\n", str, str[i + 1]);
			printf("Invalid value: uninitialized variable %c\n", str[i + 1]);
			exit(1);
		}
		else
		{
			res = a[marker].num_letter;
			res = result.num_letter | res;
		}
	}
	else if (is_implication(str, i))
	{
		marker = check_letter(a, str[i + 1], kol_a);
		if (marker == -1)
		{
			if (trass_marker == 1)
				fprintf(trass, "%s - Invalid value: uninitialized variable %c\n", str, str[i + 1]);
			printf("Invalid value: uninitialized variable %c\n", str[i + 1]);
			exit(1);
		}
		else
		{
			res = a[marker].num_letter;
			res = result.num_letter & res;
		}
	}
	else if (str[i] == '-' && str[i + 1] == '>' && (str[i + 2] >= 'a' && str[i + 2] <= 'z') && str[i + 3] == '\0')
	{
		marker = check_letter(a, str[i + 2], kol_a);
		if (marker == -1)
		{
			if (trass_marker == 1)
				fprintf(trass, "%s - Invalid value: uninitialized variable %c\n", str, str[i + 2]);
			printf("Invalid value: uninitialized variable %c\n", str[i + 2]);
			exit(1);
		}
		else
		{
			res = a[marker].num_letter;
			res = ~result.num_letter | res;
		}
	}
	else if (str[i] == '<' && str[i + 1] == '-' && (str[i + 2] >= 'a' && str[i + 2] <= 'z') && str[i + 3] == '\0')
	{
		marker = check_letter(a, str[i + 2], kol_a);
		if (marker == -1)
		{
			if (trass_marker == 1)
				fprintf(trass, "%s - Invalid value: uninitialized variable %c\n", str, str[i + 2]);
			printf("Invalid value: uninitialized variable %c\n", str[i + 2]);
			exit(1);
		}
		else
		{
			res = a[marker].num_letter;
			res = result.num_letter | (~res);
		}
	}
	else if (str[i] == '<' && str[i + 1] == '>' && (str[i + 2] >= 'a' && str[i + 2] <= 'z') && str[i + 3] == '\0')
	{
		marker = check_letter(a, str[i + 2], kol_a);
		if (marker == -1)
		{
			if (trass_marker == 1)
				fprintf(trass, "%s - Invalid value: uninitialized variable %c\n", str, str[i + 2]);
			printf("Invalid value: uninitialized variable %c\n", str[i + 2]);
			exit(1);
		}
		else
		{
			res = a[marker].num_letter;
			res = result.num_letter ^ res;
		}
	}
	else if (str[i] == '~' && (str[i + 1] >= 'a' && str[i + 1] <= 'z') && str[i + 2] == '\0')
	{
		marker = check_letter(a, str[i + 1], kol_a);
		if (marker == -1)
		{
			if (trass_marker == 1)
				fprintf(trass, "%s - Invalid value: uninitialized variable %c\n", str, str[i + 1]);
			printf("Invalid value: uninitialized variable %c\n", str[i + 1]);
			exit(1);
		}
		else
		{
			res = a[marker].num_letter;
			if (res == result.num_letter)
				return 1;
			else
				return 0;
		}
	}
	else if (str[i] == '?' && (str[i + 1] >= 'a' && str[i + 1] <= 'z') && str[i + 2] == '\0')
	{
		marker = check_letter(a, str[i + 1], kol_a);
		if (marker == -1)
		{
			if (trass_marker == 1)
				fprintf(trass, "%s - Invalid value: uninitialized variable %c\n", str, str[i + 1]);
			printf("Invalid value: uninitialized variable %c\n", str[i + 1]);
			exit(1);
		}
		else
		{
			res = a[marker].num_letter;
			res = ~(result.num_letter & res);
		}
	}
	else if (str[i] == '!' && (str[i + 1] >= 'a' && str[i + 1] <= 'z') && str[i + 2] == '\0')
	{
		marker = check_letter(a, str[i + 1], kol_a);
		if (marker == -1)
		{
			if (trass_marker == 1)
				fprintf(trass, "%s - Invalid value: uninitialized variable %c\n", str, str[i + 1]);
			printf("Invalid value: uninitialized variable %c\n", str[i + 1]);
			exit(1);
		}
		else
		{
			res = a[marker].num_letter;
			res = ~(result.num_letter | res);
		}
	}
	else
	{
		if (trass_marker == 1)
			fprintf(trass, "%s - Invalid syntax: not right operation\n", str);
		printf("Invalid syntax: not right operation\n");
		exit(1);
	}

	return res;
}

struct Bool *check_massive_letter_after_operation(struct Bool result, struct Bool *a, int kol_a)
{
	int i;
	i = 0;

	for (i; i < kol_a; i++)
		if (result.letter == a[i].letter)
		{
			a[i].num_letter = result.num_letter;
			a[kol_a].letter = NULL;
			return a;
		}
	a[kol_a].letter = result.letter;
	a[kol_a].num_letter = result.num_letter;
	return a;
}

void read_from_file(FILE *fp, FILE *trass, int trass_marker)
{
	struct Bool *massive_of_letter = (struct Bool *)malloc(N * sizeof(struct Bool));
	struct Bool result;
	char *str = (char *)malloc(2 * sizeof(str));
	char *base = (char *)malloc(N * sizeof(str));
	char *temp;
	char symbol;
	int i, kol_massive_of_letter, marker, kol_skobok;
	i = 0;
	marker = 0;
	kol_massive_of_letter = 0;
	kol_skobok = 0;
	str[0] = '\0';
	symbol = fgetc(fp);
	if (symbol == EOF)
	{ //пустой файл
		if (trass_marker == 1)
			fprintf(trass, "Invalid file: empty\n");
		printf("Invalid file: empty\n");
		exit(1);
	}

	while (symbol != EOF)
	{
		while (isspace(symbol) != 0)
			symbol = fgetc(fp);
		if (symbol == EOF)
			break;
		temp = (char *)realloc(str, i + 2);
		if (temp)
			str = temp;
		str[0] = '\0';

		while (symbol != ';')
		{ //добавляем строчку в массив без пробелов
			if (symbol == EOF)
			{
				if (trass_marker == 1)
					fprintf(trass, "%s - Invalid syntax: omitted separator between operators\n", str);
				printf("Invalid syntax: omitted separator between operators\n"); // нету ;
				exit(1);
			}
			else if (symbol == '{')
			{
				kol_skobok++;
				while (kol_skobok != 0)
				{
					symbol = fgetc(fp);
					if (symbol == '{')
						kol_skobok++;
					else if (symbol == '}')
						kol_skobok--;
					if (symbol == EOF)
					{
						if (trass_marker == 1)
							fprintf(trass, "Invalid syntax: not }\n");
						printf("Invalid syntax: not }\n");
						exit(1);
					}
				}
				symbol = fgetc(fp);
				continue;
			}    while (isspace(input) != 0)
                input = fgetc(f);
            if (input == EOF)
                break;
            temp = (char *)realloc(str, i + 2);
            if (temp)
                str = temp;
            if (isspace(input) == 0)
                {
                    if (str)
                    {
                        str[i++] = tolower(input);
                        str[i] = '\0';
                        temp = (char *)realloc(str, i + 2);
                        if (temp)
                            str = temp;
                    }
                }
            input = fgetc(f);
			else if (symbol == '}' && kol_skobok == 0)
			{
				if (trass_marker == 1)
					fprintf(trass, "Invalid syntax: not {\n");
				printf("Invalid syntax: not {\n");
				exit(1);
			}
			else if (symbol == '%')
			{ //комменты
				while (symbol != '\n')
					symbol = fgetc(fp);
			}
			else if (isspace(symbol) == 0)
			{
				if (str)
				{
					str[i++] = tolower(symbol);
					str[i] = '\0';
					temp = (char *)realloc(str, i + 2);
					if (temp)
						str = temp;
				}
			}
			symbol = fgetc(fp);
		}
		symbol = fgetc(fp); //нужно перейти на следующий после ;
		i = 0;
		while (str[i++] != '\0')
		{ //делаем обработку строчки
			if (i - 1 == 1)
			{
				if (str[i - 1] == ':' && str[i] == '=')
				{
					i = 3;
					continue;
				}
				else
				{
					if (trass_marker == 1)
						fprintf(trass, "%s - Ivalid syntax: invalid assignment\n", str);
					printf("Ivalid syntax: invalid assignment\n"); //нету :=
					exit(1);
				}
			}
			else if (i - 1 == 3 && str[i - 1] == 92)
			{
				if (str[i] >= 'a' && str[i] <= 'z' && str[i + 1] == '\0')
				{
					marker = check_letter(massive_of_letter, str[i], kol_massive_of_letter);
					if (marker == -1)
					{
						if (trass_marker == 1)
							fprintf(trass, "%s - Invalid value: uninitialized variable %c\n", str, str[i]);
						printf("Invalid value: uninitialized variable %c\n", str[i]);
						exit(1);
					}
					else
					{
						result.num_letter = !massive_of_letter[marker].num_letter;
						if (trass_marker == 1)
							fprintf(trass, "%s completed successfully, %c = %d\n", str, result.letter, result.num_letter);
						massive_of_letter = check_massive_letter_after_operation(result, massive_of_letter, kol_massive_of_letter++);
						if (massive_of_letter[kol_massive_of_letter - 1].letter == NULL)
							kol_massive_of_letter--;
						break;
					}
				}
				else
				{
					if (trass_marker)
						fprintf(trass, "%s - Invalid syntax: after denial not char\n", str);
					printf("Invalid syntax: after denial not char\n");
					exit(1);
				}
			}
			else if (tolower(str[i - 1]) >= 'a' && tolower(str[i - 1]) <= 'z' && (i - 1 == 0 || i - 1 == 3))
			{
				if (tolower(str[i - 1]) == 'r' && i - 1 == 0)
				{
					massive_of_letter = check_for_read(massive_of_letter, str, kol_massive_of_letter++, base, trass, trass_marker);
					if (massive_of_letter[kol_massive_of_letter - 1].letter == NULL)
						kol_massive_of_letter--;
					if (trass_marker == 1)
						fprintf(trass, "%s completed successfully, %c = %d\n", str, massive_of_letter[kol_massive_of_letter - 1].letter, massive_of_letter[kol_massive_of_letter - 1].num_letter);
					break;
				}
				else if (tolower(str[i - 1]) == 'w' && i - 1 == 0)
				{
					check_for_write(massive_of_letter, str, kol_massive_of_letter, base, trass, trass_marker);
					break;
				}
				else
				{
					if (i - 1 == 0) //если самая первая буква
						result.letter = str[i - 1];
					else
					{
						if ((marker = check_letter(massive_of_letter, str[i - 1], kol_massive_of_letter)) != -1)
						{
							result.num_letter = massive_of_letter[marker].num_letter;
						}
						else
						{
							if (trass_marker == 1)
								fprintf(trass, "%s - Invalid value: uninitialized variable %c\n", str, str[i - 1]);
							printf("Invalid value: uninitialized variable %c\n", str[i - 1]);
							exit(1);
						}
					}
				}
			}
			else if (i - 1 == 4)
			{
				if (str[i - 1] == '+' || str[i - 1] == '&' || str[i - 1] == '-' || str[i - 1] == '<' || str[i - 1] == '~' || str[i - 1] == '?' || str[i - 1] == '!')
				{
					result.num_letter = operation(result, str, massive_of_letter, kol_massive_of_letter, trass, trass_marker);
					if (trass_marker == 1)
						fprintf(trass, "%s completed successfully, %c = %d\n", str, result.letter, result.num_letter);
					massive_of_letter = check_massive_letter_after_operation(result, massive_of_letter, kol_massive_of_letter++);
					if (massive_of_letter[kol_massive_of_letter - 1].letter == NULL)
						kol_massive_of_letter--;
					break;
				}
				else
				{
					if (trass_marker == 1)
						fprintf(trass, "%s - Invalid syntax: not operation\n", str);
					printf("Invalid syntax: not operation\n");
					exit(1);
				}
			}
			else
			{
				if (trass_marker == 1)
					fprintf(trass, "%s - Invalid syntax: argument 1 or 2 not char\n", str);
				printf("Invalid syntax: argument 1 or 2 not char\n");
				exit(1);
			}
		}
		i = 0; //обнуляем счетчик массива str
		kol_skobok = 0;
		marker = -1;
	}

	free(massive_of_letter);
	free(base);
}

int main(int argc, char *argv[])
{
	FILE *fp;
	char *filename = argv[1];
	FILE *trace;
	char *tracename = argv[3];
	int i;
	i = 0;
	trace = NULL;

	if (argc == 1 || argc > 4)
	{
		printf("Too many arguments or 0\n");
		exit(1);
	}
	else
	{
		if (fp = fopen(filename, "r"))
		{
			if (argc == 3)
			{
				printf("Low arguments for flag\n");
				exit(1);
			}
			else if (argc == 4)
			{
				if (strcmp(argv[2], "/trace") == 0)
				{
					if (trace = fopen(tracename, "r"))
					{
						fclose(trace);
						trace = fopen(tracename, "w+");
						read_from_file(fp, trace, 1);
					}
					else
					{
						printf("Invalid trass file: not exist\n");
						exit(1);
					}
				}
				else
				{
					printf("Invalid flag: not /trace\n");
					exit(1);
				}
			}
			else
			{
				fp = fopen(filename, "r");
				read_from_file(fp, trace, 0);
			}
		}
		else
		{
			printf("Invalid file: not exist\n");
			exit(1);
		}
	}

	return 0;
}