#include <stdlib.h>
#include <stdio.h>
#include <math.h>

 int straight1 (int i)
{
  return  - i - 10;
}
 int straight2 (int i)
{
  return  - i - 20;
}
int in_strip(int i, int j)
{
return (j >= straight2(i)) && (j <= straight1(i));
}
int max(int a, int b)
{
  return (a > b) ? a : b;
}
int min(int a, int b)
{
  return (a < b) ? a : b;
}
int mod(int a, int b)
{
return a % b >= 0 ? a % b : a % b + b;
}
int main(void)
{
int k;
int i = -30, j = -4, l = 12;
int next_i, next_j, next_l;

for (k = 0; !in_strip(i, j) && k < 50; ++k) {
	
	next_i = abs(i - j) + min(mod(j, 10), mod(l * k, 10)) - 20;
	next_j = mod(max(k - j, min(j, max(i - l, j - l))), 30);
	next_l = mod(l*l, 20) - mod(max(i, j), (k + 1));
	i = next_i;
	j = next_j;
	l = next_l;
}
printf("%sside\n", in_strip(i, j) ? "In": "Out");
printf("i = %d, j = %d, l = %d, k = %d\n", i, j, l, k);

return 0;
}
