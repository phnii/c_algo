#include <stdio.h>

int gcd(int x, int y)
{
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}

int main(void)
{
  int x, y;
  puts("二つの整数の最大公約数を求めます");
  printf("整数を入力せよ:");
  scanf("%d", &x);
  printf("整数を入力せよ:");
  scanf("%d", &y);

  printf("%dと%dの最大公約数は%dです\n", x, y, gcd(x, y));
}