#include <stdio.h>

int main()
{
	printf("Matrix size:");
	int n,count;
	while (scanf("%d",&n) == 1)
	{
	printf("Matrix:\n");
	int i0 = (n - 1) / 2;
	int line_1 = i0;
	int line_2 = line_1 + 1;
	int column_1 = line_1 + 1;
	int column_2 = line_1 - 1;
	int a[n][n];
	count = n*n;
	int i, j;
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	while (count > 0){
		for (int i = i0; i <= column_1; i++){
			if (count <= 0) break;
			printf("%d", a[line_1][i]);
			printf("%s"," ");
			count--;
		}
		for (int i = line_1 + 1; i <= column_1; i++){
			if (count <= 0) break;
			printf("%d", a[i][column_1]);
			printf("%s"," ");
			count --;
		}
		for (int i = column_1 - 1; i >= column_2; i--){
			if (count <= 0) break;
			printf("%d", a[line_2][i]);
			printf("%s"," ");
			count--;
		}
		for (int i = line_2 - 1; i >= column_2; i--){
			if (count <= 0) break;
			printf("%d", a[i][column_2]);
			printf("%s"," ");
			count--;
		}
		if (count == n * n - 7) i0 = i0;
		else i0--;
		line_1 -= 1;
		column_1 += 1;
		line_2 += 1;
		column_2 -= 1;
		
	}
	printf ("\nMatrix size: ");
	}
}