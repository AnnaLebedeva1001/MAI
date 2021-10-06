#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int max(int x, int y)
{
  return (x > y) ? x : y;
}
int min(int x, int y)
{
  return (x < y) ? x : y;
}
int mod(int a, int b)
{
return a % b >= 0 ? a % b : a % b + b;
}
int main(void)
{
FILE *f1;
int k;
int x = -30, y = -4, z = 12;
int next_x, next_y, next_z;


for (k = 0; k < 50; ++k)  
{
	next_x = abs(x - y) + min(mod(y, 10), mod(z * k, 10)) - 20;
	next_y = mod(max(k - y, min(y, max(x - z, y - z))), 30);
	next_z = mod(z*z, 20) - mod(max(x, y), (k + 1));
	x = next_x;
	y = next_y;
	z = next_z;

	f1 = fopen("coordinaty.txt", "a");
	fprintf(f1,"%d, %d, %d\n", x, y, z);
	fclose(f1);
}
return 0;

}

