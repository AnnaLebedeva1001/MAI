#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#define N 100

struct Plenty
{
	char name = 1;
	int* massive = (int*)malloc(N * sizeof(int));
	int top = 0;
};

int compare_plenty_plus(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int compare_plenty_minus(const void* a, const void* b)
{
	return (-1) * (*(int*)a - *(int*)b);
}

int find_index_min(int* a, int kol_a)
{
	int i, min, index_min; i = 1; min = a[0]; index_min = 0;
	for (i; i < kol_a; i++)
		if (a[i] < min)
		{
			min = a[i];
			index_min = i;
		}
	return index_min;
}

int find_index_max(int* a, int kol_a)
{
	int i, max, index_max; i = 1; max = a[0]; index_max = 0;
	for (i; i < kol_a; i++)
		if (a[i] > max)
		{
			max = a[i];
			index_max = i;
		}
	return index_max;
}

double average(int* a, int kol_a)
{
	double res;
	int i;
	res = 0; i = 0;

	for (i; i < kol_a; i++)
		res += a[i];
	res /= double(kol_a);
	return res;
}

int most_counter(int* a, int kol_a)
{
	int i, j, number_counter, counter, new_counter;
	i = 0; j = 0;  number_counter = 0; counter = 0; new_counter = 0;

	for (i; i < kol_a; i++)
	{
		j = i; new_counter = 0;
		if (i > 0 && a[i] == number_counter) // если число в массиве после первого = наиболее встречаемому на данном этапе, то сразу переходим к следующему
			continue;
		else
		{
			for (j; j < kol_a; j++)
				if (a[i] == a[j])
					new_counter++;
			if (new_counter > counter)
			{
				number_counter = a[i];
				counter = new_counter;
			}
		}
	}
	return number_counter;
}

double max_deviation(int* a, int kol_a, double average)
{
	double res;
	int i;
	res = 0; i = 0;

	for (i; i < kol_a; i++)
		if (fabs(double(a[i]) - average) > res)
			res = fabs(double(a[i]) - average);
	return res;
}

int check_for_empty(FILE* fp, char* argv)
{
	char symbol;
	symbol = fgetc(fp);
	while (isspace(symbol) != 0)
		symbol = fgetc(fp);

	if (symbol == EOF)
	{
		fclose(fp);
		fp = fopen(argv, "r");
		return 1;
	}
	else
	{
		fclose(fp);
		fp = fopen(argv, "r");
		return 0;
	}
}

int for_random(char* str, int kol_str, char* result)
{
	int marker_for_minus, res, i;
	marker_for_minus = 0; res = 0; i = 0;

	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
		kol_str++;
	if (str[kol_str] == '-')
	{
		marker_for_minus = 1;
		kol_str++; // пропускаем минус
	}
	while (isspace(str[kol_str]) == 0 && str[kol_str] != ',' && str[kol_str] != ';')
	{
		result[i++] = str[kol_str++];
		result[i] = '\0';
	}
	if (marker_for_minus)
		res = atoi(result) * (-1);
	else
		res = atoi(result);
	return res;
}

struct Plenty* load(struct Plenty* a, int kol_a, char* str, int kol_str)
{
	FILE* fp;
	struct Plenty plenty;
	char* file = (char*)malloc(N * sizeof(char));
	char* number = (char*)malloc(N * sizeof(char));
	char symbol, symbol_file;
	int i, marker_for_minus;
	i = 0;
	marker_for_minus = 0;

	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
		kol_str++;

	symbol = tolower(str[kol_str++]);
	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы до ,
		kol_str++;
	kol_str++; // пропускаем ,

	for (i; i < kol_a; i++)
	{ // проверяем был ли уже загружен этот массив
		if (a[i].name == symbol && a[i].top == 0)
			kol_a = i;
		else if (a[i].name == symbol)
		{
			printf("Massive %c has already been downloaded\n", tolower(symbol));
			exit(1);
		}
	}
	i = 0;
	plenty.name = tolower(symbol);

	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
		kol_str++;

	while (isspace(str[kol_str]) == 0 && str[kol_str] != ';')
	{
		file[i++] = str[kol_str++];
		file[i] = '\0';
	}

	if (fp = fopen(file, "r"))
	{
		if (check_for_empty(fp, file))
		{
			printf("File %s is empty\n", file);
			exit(1);
		}
		else
		{
			symbol_file = fgetc(fp);
			i = 0;
			while (symbol_file != EOF)
			{
				while (isspace(symbol_file) != 0)
					symbol_file = fgetc(fp);
				if (symbol_file == EOF)
					continue;
				while (isspace(symbol_file) == 0 && symbol_file != EOF)
				{
					if ((symbol_file >= '0' && symbol_file <= '9') || symbol_file == '-')
					{
						if (symbol_file == '-') 
						{
							if (marker_for_minus)
							{ //если минус уже был
								while (isspace(symbol_file) == 0)
								{ 
									// доходим до конца слова
									symbol_file = fgetc(fp);
									if (symbol_file == EOF)
										break;
								}
								if (symbol_file == EOF)
								{
									i = 0;
									break;
								}
								while (isspace(symbol_file) != 0) // пропускаем все пробелы 
									symbol_file = fgetc(fp);
								i = 0;
								marker_for_minus = 0;
								continue;
							}
							else
							{
								marker_for_minus = 1;
								symbol_file = fgetc(fp);
								continue;
							}
						}
						number[i++] = symbol_file;
						number[i] = '\0';
						symbol_file = fgetc(fp);
					}
					else
					{
						while (isspace(symbol_file) == 0)
						{ // доходим до конца слова
							symbol_file = fgetc(fp);
							if (symbol_file == EOF)
								break;
						}
						if (symbol_file == EOF)
						{
							i = 0;
							break;
						}
						while (isspace(symbol_file) != 0) // пропускаем все пробелы 
							symbol_file = fgetc(fp);
						i = 0; marker_for_minus = 0;
					}
				}
				if (i != 0 || (symbol_file == EOF && i != 0))
				{
					if (marker_for_minus)
						plenty.massive[plenty.top++] = atoi(number) * (-1);
					else
						plenty.massive[plenty.top++] = atoi(number);
				}
				i = 0;
				marker_for_minus = 0;
			}
		}
		printf("Massive %c downloaded\n\n", symbol);
	}
	else {
		printf("File %s not exist\n", file);
		exit(1);
	}

	a[kol_a] = plenty;
	fclose(fp);
	free(file);
	free(number);
	return a;
}

void save(struct Plenty* a, int kol_a, char* str, int kol_str)
{
	FILE* fp = NULL;
	char* file = (char*)malloc(N * sizeof(char));
	char symbol;
	int i, j;
	i = 0; j = 0;

	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
		kol_str++;

	symbol = tolower(str[kol_str++]);
	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы до ,
		kol_str++;
	kol_str++; // пропускаем ,

	for (i; i < kol_a; i++)
	{ // проверяем был ли загружен этот массив
		if (a[i].name == symbol)
		{
			while (isspace(str[kol_str]) != 0) // пропускаем все пробелы после ,
				kol_str++;

			while (isspace(str[kol_str]) == 0 && str[kol_str] != ';')
			{
				file[j++] = str[kol_str++];
				file[j] = '\0';
			}
			fp = fopen(file, "a+");
			j = 0;

			fprintf(fp, "Massive %c:\n", symbol);
			if (a[i].top == 0)
				fprintf(fp, "Empty");
			else 
			{
				for (j; j < a[i].top; j++)
					fprintf(fp, "%d ", a[i].massive[j]);
			}
			fprintf(fp, "\n\n");

			printf("Massive %c saved in %s\n\n", symbol, file);
			fclose(fp);
			free(file);
			return;
		}
	}

	// если массив не нашелся
	printf("Massive %c not found\n", symbol);
	if (fp)
		fclose(fp);
	free(file);
	exit(1);
}

struct Plenty* random(struct Plenty* a, int kol_a, char* str, int kol_str)
{
	char* result = (char*)malloc(N * sizeof(char));
	char symbol;
	int i, count, lb, rb, j;
	i = 0; count = 0; lb = 0; rb = 0; j = 0;

	srand(time(NULL));

	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
		kol_str++;

	symbol = tolower(str[kol_str++]);
	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы до ,
		kol_str++;
	kol_str++; // пропускаем ,

	count = for_random(str, kol_str, result);
	while (str[kol_str] != ',')
		kol_str++;
	kol_str++;
	
	lb = for_random(str, kol_str, result);
	while (str[kol_str] != ',')
		kol_str++;
	kol_str++;

	rb = for_random(str, kol_str, result);

	for (i; i < kol_a; i++)
	{
		if (a[i].name == symbol)
		{
			if (a[i].top == 0)
			{
				for (j; j < count; j++) // заполняем случайными числами из диапазона [lb, rb]
					a[i].massive[a[i].top++] = lb + rand() % (rb - lb + 1);
			}
			else
			{
				printf("Massive %c has already been downloaded\n", symbol);
				exit(1);
			}
			printf("Massive %c loaded with random numbers from the segment [%d, %d], count = %d\n\n", symbol, lb, rb, count);
			free(result);
			return a;
		}
	}

	//если не нашлось указанного массива
	printf("Massive %c not found\n", symbol);
	free(result);
	exit(1);
}

struct Plenty* concat(struct Plenty* a, int kol_a, char* str, int kol_str)
{
	char symbol_1, symbol_2;
	int massive_symbol_1, massive_symbol_2; // индексы массивов в массиве структур
	int marker, i; // Для проверки на наличие массивов 1 и 2
	marker = 0; i = 0;
	massive_symbol_1 = 0;
	massive_symbol_2 = 0;

	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
		kol_str++;
	symbol_1 = tolower(str[kol_str++]);
	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы до ,
		kol_str++;
	kol_str++; // пропускаем ,

	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
		kol_str++;
	symbol_2 = tolower(str[kol_str++]);

	for (i; i < kol_a; i++) // проверяем на наличие массивов 1 и 2
		if (a[i].name == symbol_1 || a[i].name == symbol_2)
		{
			if (a[i].name == symbol_1)
				massive_symbol_1 = i;
			else if (a[i].name == symbol_2)
				massive_symbol_2 = i;
			marker++;
		}
	if (marker == 2) {
		i = 0;
		for (i; i < a[massive_symbol_2].top; i++)
			a[massive_symbol_1].massive[a[massive_symbol_1].top++] = a[massive_symbol_2].massive[i];
	}
	else {
		printf("Massive %c or massive %c not found\n", symbol_1, symbol_2);
		exit(1);
	}

	printf("Concat of massives %c and %c completed successfully, result saved in massive %c\n\n", symbol_1, symbol_2, symbol_1);
	return a;
}

struct Plenty* remove_from_plenty(struct Plenty* a, int kol_a, char* str, int kol_str)
{
	char* result = (char*)malloc(N * sizeof(char));
	char symbol;
	int i, kol_elemets, index, j;
	i = 0; index = 0; kol_elemets = 0; j = 0;

	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
		kol_str++;
	symbol = tolower(str[kol_str++]);
	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы до ,
		kol_str++;
	kol_str++; // пропускаем ,

	index = for_random(str, kol_str, result);
	while (str[kol_str] != ',')
		kol_str++;
	kol_str++;

	kol_elemets = for_random(str, kol_str, result);
	printf("index = %d\nkol_elements = %d\n", index, kol_elemets);

	for (i; i < kol_a; i++) 
	{
		if (a[i].name == symbol) 
		{
			if (a[i].top >= index + kol_elemets) 
			{
				 // количество элементов в массиве должно быть больше или равно сумме индекса с которого мы удаляем и количества удаляемых элементов
				j = index + kol_elemets;
				for (j; j < a[i].top; j++)
					a[i].massive[index++] = a[i].massive[j];
				a[i].top -= kol_elemets;
			}
			else
			{
				printf("In massive %c not enough elements\n", symbol);
				exit(1);
			}
			printf("Removed from massive %c completed successfully\n\n", symbol);
			free(result);
			return a;
		}
	}

	// если массив не найден
	printf("Massive %c not found\n", symbol);
	free(result);
	exit(1);
}

struct Plenty* copy(struct Plenty* a, int kol_a, char* str, int kol_str)
{
	char* result = (char*)malloc(N * sizeof(char));
	char symbol_1, symbol_2;
	int i, marker, lindex, rindex;
	int massive_symbol_1, massive_symbol_2; // индексы массивов в массиве структур
	i = 0; marker = 0; lindex = 0; rindex = 0;
	massive_symbol_1 = 0;
	massive_symbol_2 = 0;

	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
		kol_str++;
	symbol_1 = tolower(str[kol_str++]);
	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы до ,
		kol_str++;
	kol_str++; // пропускаем ,

	lindex = for_random(str, kol_str, result);
	while (str[kol_str] != ',')
		kol_str++;
	kol_str++;

	rindex = for_random(str, kol_str, result);
	while (str[kol_str] != ',')
		kol_str++;
	kol_str++;

	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
		kol_str++;
	symbol_2 = tolower(str[kol_str]);

	for (i; i < kol_a; i++) // проверяем на наличие массивов 1 и 2
		if (a[i].name == symbol_1 || a[i].name == symbol_2)
		{
			if (a[i].name == symbol_1)
				massive_symbol_1 = i;
			else if (a[i].name == symbol_2)
				massive_symbol_2 = i;
			marker++;
		}
	if (marker == 2)
	{
		if (a[massive_symbol_1].top > rindex)
		{ 
			// если индекс верхней границы меньше чем количество элементов в массиве 1
			i = lindex; a[massive_symbol_2].top = 0;
			for (i; i < rindex + 1; i++)
				a[massive_symbol_2].massive[a[massive_symbol_2].top++] = a[massive_symbol_1].massive[i];
		}
		else
		{
			printf("In massive %c not enough elements\n", symbol_1);
			exit(1);
		}
	}
	else
	{
		printf("Massive %c or massive %c not found\n", symbol_1, symbol_2);
		exit(1);
	}

	printf("Massive %c [%d, %d] copied in massive %c, result saved in massive %c\n\n", symbol_1, lindex, rindex, symbol_2, symbol_2);
	free(result);
	return a;
}

struct Plenty* sort_plenty(struct Plenty* a, int kol_a, char* str, int kol_str)
{
	char symbol, operation;
	int i;
	i = 0;

	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
		kol_str++;
	symbol = tolower(str[kol_str++]);

	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
		kol_str++;
	operation = str[kol_str];
	for (i; i < kol_a; i++)
	{
		if (a[i].name == symbol)
		{
			if (operation == '+')
				qsort(a[i].massive, a[i].top, sizeof(int), compare_plenty_plus);
			else
				qsort(a[i].massive, a[i].top, sizeof(int), compare_plenty_minus);
			printf("Sorted %c with %c completed successfully\n\n", symbol, operation);
			return a;
		}
	}

	// если массив не найден
	printf("Massive %c not found\n", symbol);
	exit(1);
}

struct Plenty* permute(struct Plenty* a, int kol_a, char* str, int kol_str)
{
	char symbol;
	int i, j, k, temp;
	i = 0; j = 0; k = 0;
	temp = 0;

	srand(time(NULL));

	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
		kol_str++;
	symbol = tolower(str[kol_str++]);

	for (i; i < kol_a; i++)
	{
		if (a[i].name == symbol) 
		{
			for (j; j < a[i].top; j++) 
			{
				k = rand() % (a[i].top); // не включая a[i].top
				temp = a[i].massive[k];
				a[i].massive[k] = a[i].massive[j];
				a[i].massive[j] = temp;
			}
			printf("Permute in massive %c completed successfully\n\n", symbol);
			return a;
		}
	}

	// если массив не найден
	printf("Massive %c not found\n", symbol);
	exit(1);
}

void stat(struct Plenty* a, int kol_a, char* str, int kol_str)
{
	char symbol;
	int i, index_min, index_max;
	i = 0; index_min = 0; index_max = 0;


	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
		kol_str++;
	symbol = tolower(str[kol_str++]);

	for (i; i < kol_a; i++)
	{
		if (a[i].name == symbol)
		{
			if (a[i].top == 0)
				return;
			else {
				printf("Stat of  massive %c:\n", symbol);
				printf("Size = %d\n", a[i].top);
				index_min = find_index_min(a[i].massive, a[i].top);
				index_max = find_index_max(a[i].massive, a[i].top);
				printf("Minimal element = %d, his index = %d\nMaximum element = %d, his index = %d\n", a[i].massive[index_min], index_min, a[i].massive[index_max], index_max);
				printf("Most common element = %d\n", most_counter(a[i].massive, a[i].top));
				printf("Average = %lf\n", average(a[i].massive, a[i].top));
				printf("Max deviation from average = %lf\n\n", max_deviation(a[i].massive, a[i].top, average(a[i].massive, a[i].top)));
			}
			return;
		}
	}

	// если массив не найден
	printf("Massive %c not found\n", symbol);
	exit(1);
}

struct Plenty* clear(struct Plenty* a, int kol_a, char* str, int kol_str)
{
	char symbol;
	int i, j;
	i = 0; j = 0;
	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы до (
		kol_str++;
	kol_str++; // пропускаем (
	
	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
		kol_str++;
	symbol = tolower(str[kol_str]);

	for (i; i < kol_a; i++)
	{ // проверяем был ли загружен этот массив
		if (a[i].name == symbol) 
		{
			free(a[i].massive);
			a[i].massive = (int*)malloc(N * sizeof(int));
			a[i].top = 0;
			printf("Massive %c are cleared\n\n", symbol);
			return a;
		}
	}
	
	//если не был загружен
	printf("Massive %c not found\n", symbol);
	exit(1);
}

void print(struct Plenty* a, int kol_a, char* str, int kol_str)
{
	char* number = (char*)malloc(N * sizeof(char));
	char symbol;
	int i, j; i = 0; j = 0;
	int border_1, border_2;

	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
		kol_str++;

	symbol = tolower(str[kol_str++]);
	while (isspace(str[kol_str]) != 0) // пропускаем все пробелы до ,
		kol_str++;
	kol_str++; // пропускаем ,

	for (i; i < kol_a; i++)
	{ // проверяем существует ли данный массив
		if (a[i].name == symbol) 
		{
			while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
				kol_str++;

			if (str[kol_str] == 'a')
			{
				printf("Massive %c:\n", symbol);
				if (a[i].top == 0)
					printf("Empty");
				else
				{
					for (j; j < a[i].top; j++)
						printf("%d ", a[i].massive[j]);
				}
				putchar('\n'); putchar('\n');
			}
			else 
			{
				while (isspace(str[kol_str]) == 0 && str[kol_str] != ',')
				{
					number[j++] = str[kol_str++];
					number[j] = '\0';
				}
				border_1 = atoi(number); j = 0;

				while (isspace(str[kol_str]) != 0) // пропускаем все пробелы до ,
					kol_str++;
				kol_str++; // пропускаем ,
				while (isspace(str[kol_str]) != 0) // пропускаем все пробелы
					kol_str++;

				while (isspace(str[kol_str]) == 0 && str[kol_str] != ',')
				{
					number[j++] = str[kol_str++];
					number[j] = '\0';
				}
				if ((border_2 = atoi(number)) > a[i].top - 1)
				{
					printf("Going beyond array boundaries to %d\n", border_2);
					exit(1);
				}
				else
				{
					j = border_1;
					printf("Massive %c from %d to %d:\n", symbol, border_1, border_2);
					for (j; j < border_2 + 1; j++)
						printf("%d ", a[i].massive[j]);
					putchar('\n'); putchar('\n');
				}
			}
			return; // выходим из функции
		}
	}
	// если не нашлось
	free(number);
	printf("This array %c does not exist\n", symbol);
	exit(1);
}

int main()
{
	FILE* fp;
	struct Plenty a; // для заполнения массива структур пустыми структурами
	struct Plenty* plenty = (struct Plenty*)malloc(N * sizeof(struct Plenty)); // массив структур
	char* str = (char*)malloc(N * sizeof(char)); // для считывания строки
	char* command = (char*)malloc(N * sizeof(char)); // для команды
	int i, j, kol_plenty; // kol_plenty - количество структур в plenty
	i = 0; j = 0; kol_plenty = 0;
	fp = fopen("/home/anna/projects/3sem/FundAlg/4lab/z1/test.txt", "r");

	for (i; i < N; i++)
		plenty[i] = a;
	i = 0;

	while (fgets(str, N, fp))
	{
		while (str[i] != '\0')
		{
			while (isspace(str[i]) != 0) // пропускаем все пробелы в начале (если они есть)
				i++;

			while (isspace(str[i]) == 0 && str[i] != '(') 
			{ 
				// считываем команду
				command[j++] = str[i++];
				command[j] = '\0';
			}

			if (strcmp(command, "Load") == 0)
			{
				plenty = load(plenty, kol_plenty++, str, i);
				if (plenty[kol_plenty - 1].name == 1) // если новая структура не добавилась
					kol_plenty--;
			}
			else if (strcmp(command, "Save") == 0) {
				save(plenty, kol_plenty, str, i);
			}
			else if (strcmp(command, "Rand") == 0) {
				plenty = random(plenty, kol_plenty, str, i);
			}
			else if (strcmp(command, "Concat") == 0) {
				plenty = concat(plenty, kol_plenty, str, i);
			}
			else if (strcmp(command, "Free") == 0) {
				plenty = clear(plenty, kol_plenty, str, i);
			}
			else if (strcmp(command, "Remove") == 0) {
				plenty = remove_from_plenty(plenty, kol_plenty, str, i);
			}
			else if (strcmp(command, "Copy") == 0) {
				plenty = copy(plenty, kol_plenty, str, i);
			}
			else if (strcmp(command, "Sort") == 0) {
				plenty = sort_plenty(plenty, kol_plenty, str, i);
			}
			else if (strcmp(command, "Permute") == 0) {
				plenty = permute(plenty, kol_plenty, str, i);
			}
			else if (strcmp(command, "Stat") == 0) {
				stat(plenty, kol_plenty, str, i);
			}
			else if (strcmp(command, "Print") == 0) {
				print(plenty, kol_plenty, str, i);
			}

			while (str[i] != ';') // пропускаем все до ;
				i++;
			i++; // пропускаем ; 
			while (isspace(str[i]) != 0)
				i++;
			j = 0;
		}
		i = 0; j = 0;
	}

	free(plenty);
	free(command);
	fclose(fp);
	return 0;
}