#include <stdio.h>

int NOK(int x, int y)
{
  return x * y / NOD(x, y);
}

int NOD(int x, int y)
{
  while (x != y)
  {
    if (x > y)
      x = x - y;
    else
      y = y - x;
  }
  return x;
}

int main()
{
  int y, x;
  printf("Введите целые числа через пробел: ");
  scanf("%d %d", &x, &y);
  printf("НОД %d НОК %d\n", NOD(x, y), NOK(x, y));
}