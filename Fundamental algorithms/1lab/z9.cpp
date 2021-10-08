#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
// #include <conio.h>
#include <time.h>

int main() {
	int* arr1 = NULL, *arr2=NULL, *arr3=NULL;
	int n, m;
	int i, j, dif = 100;
	printf("enter size of array A: ");
	scanf("%d", &n);
	if (n < 0) {
		printf("invalid array size input");
		exit(-1);
	}
	arr1 = (int*)malloc(n * sizeof(int));
	arr3 = (int*)malloc(n * sizeof(int));

	srand(time(NULL));
	for (i = 0; i < n; i++)
		arr1[i] = rand() % 100;

	printf("array A:\n");
	for (i = 0; i < n; i++)
		printf("%d ", *(arr1 + i));

	printf("\nenter size of array B: ");
	scanf("%d", &m);
	if (m < 0) {
		printf("invalid array size input");
		exit(-1);
	}
	arr2 = (int*)malloc(m * sizeof(int));

	/* Ввод массива B*/
	srand(time(NULL));
	for (i = 0; i < m; i++)
		arr2[i] = rand() % 100;

	printf("array B:\n");
	for (i = 0; i < m; i++)
		printf("%d ", *(arr2 + i));

	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++) {
			if (abs(arr1[i] - arr2[j]) < abs(arr1[i] - dif)) {
			dif = arr2[j];
			arr3[i] = arr1[i] + dif;
			}
		}
		dif = 100;
	}

	printf("\narray C:\n");
	for (i = 0; i < n; i++) {
		printf("%d ", *(arr3 + i));
	}

	free(arr1);
	free(arr2);
	free(arr3);
	return 0;
}

