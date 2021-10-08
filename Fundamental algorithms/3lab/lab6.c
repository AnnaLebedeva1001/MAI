#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

#pragma warning(disable: 4996)

typedef struct MyStruct
{
	int field1;
	char field2;
	char* field3;
} MyStruct, *PMyStruct;

typedef int (*MyStructComparer)(PMyStruct left, PMyStruct right);

int compareByField1(PMyStruct left, PMyStruct right)
{
	if (left->field1 == right->field1)
	{
		return 0;
	}
	else if (left->field1 < right->field1)
	{
		return -1;
	}
	return 1;
}

int compareByField3(PMyStruct left, PMyStruct right)
{
	int comparisonResult = strcmp(left->field3, right->field3);
	if (!comparisonResult)
	{
		return 0;
	}
	else if (comparisonResult < 0)
	{
		return -1;
	}
	return 1;
}

int compareByField1AndField3(PMyStruct left, PMyStruct right)
{
	int comparisonResult = compareByField1(left, right);
	if (comparisonResult)
	{
		return comparisonResult;
	}
	return compareByField3(left, right);
}

void sort(PMyStruct array, size_t count, MyStructComparer comparer)
{
	int i, j, comparisonResult;
	MyStruct temp;
	for (i = 0; i < count - 1; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			comparisonResult = comparer(array + i, array + j);
			if (comparisonResult == 1)
			{
				temp = *(array + i); // array[i]
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

char* createRandomAlphanumericString(size_t minLen, size_t maxLen)
{
	const char* symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int i;
	size_t len = rand() % (maxLen - minLen + 1) + minLen;
	char* result = (char*)malloc(sizeof(char) * (len + 1));
	for (i = 0; i < len; i++)
	{
		result[i] = symbols[rand() % strlen(symbols)];
	}
	result[len] = 0;
	return result;
}

void printStructsArray(PMyStruct array, size_t count, FILE* stream)
{
	int i;
	fprintf(stream, "\n[\n");
	for (i = 0; i < count; i++)
	{
		fprintf(stream, "\t{ Field1 = %d, Field2 = %c, Field3 = %s }",
			array[i].field1, array[i].field2, array[i].field3);
		fprintf(stream, "\n");
	}
	fprintf(stream, "]\n");
}

int main()
{
	int i;
	srand((unsigned)time(NULL));
	size_t structsArraySize = rand() % 11 + 5;
	PMyStruct structsArray = (PMyStruct)malloc(sizeof(MyStruct) *
		structsArraySize);
	for (i = 0; i < structsArraySize; i++)
	{
		structsArray[i].field1 = rand() % 3 + 10;
		structsArray[i].field2 = rand() % 76 + 48;
		structsArray[i].field3 = createRandomAlphanumericString(5, 15);
	}
	printStructsArray(structsArray, structsArraySize, stdout);
	sort(structsArray, structsArraySize, compareByField1);
	printf("Sorted array:");
	printStructsArray(structsArray, structsArraySize, stdout);
	sort(structsArray, structsArraySize, compareByField3);
	printf("Sorted array:");
	printStructsArray(structsArray, structsArraySize, stdout);
	sort(structsArray, structsArraySize, compareByField1AndField3);
	printf("Sorted array:");
	printStructsArray(structsArray, structsArraySize, stdout);
	for (i = 0; i < structsArraySize; i++)
	{
		free(structsArray[i].field3);
	}
	free(structsArray);
}