#include <stdio.h>
#include <limits.h>
enum { maxn = 8 };
enum { maxm = 8 };
int main() 
{
	int a[maxn][maxm];
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	int i, j;
	int max = INT_MIN, min = INT_MAX;
	int k = 0;
	
	for (i = 0; i != n; i++)
		for (j = 0; j != m; j++)
		scanf ("%d", &a[i][j]);
		
			for (i = 0; i <= n - 1; i++)
				for (j = 0; j <= m - 1; j++)
					 if (a[i][j] < min) min = a[i][j];
					 
			j = 0;
			while (j <= m - 1)
			{				
				for (i = 0; i <= n - 1; i++)
					if(a[i][j] == min) 
					{
					k++;
					j++;
					}
				j++;
			}
					
			for (i = 0; i <= n - 1; i++)
				for (j = 0; j <= m - 1; j++)
					if (a[i][j] > max) max = a[i][j];
					
			for (i = 0; i <= n - 1; i++)
				for (j = 0; j <= m - 1; j++)
					if (a[i][j] == max) 
					{
					a[i][j] = 0;
					a[i][j] = k;
					}
					
				for (i = 0; i <= n - 1; i++)
				{
				for (j = 0; j <= m - 1; j++)
					{
					printf("%d ", a[i][j]);
					}
					printf("\n");
				}
}
