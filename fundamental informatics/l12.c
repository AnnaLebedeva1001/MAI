#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
printf("number = ");
int n, m, a, b, k = 0;
while(scanf("%d", &n) != EOF)
	{
		m = n;
		while(m != 0)
		{
				a = m % 10;
				b = (m % 100 - a) / 10;
				if(abs(b) > abs(a)) 
				{   
				k = k * 100 + b * 10 + a;
				m /= 100;
				} 	
				else 
				{
				k = k * 100 + a * 10 + b;
				m /= 100;
				}
		}
		while(k != 0)
		{
			m = m * 10 + k % 10;
			k /= 10;
		}
	printf("new_number = %d\n", m);
	printf("number = ");
	}
	printf("\n");
	return 0;
}
	
