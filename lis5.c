#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[], int n)
{
  int max = a[0];

  for (int i = 0; i < n; i++)
    if (a[i] > max) max = a[i];

  return max;
}

int main(void)
{
  int number;
  printf("人数: ");
  scanf("%d", &number);

  int *height = calloc(number, sizeof(int));

  printf("%d人の身長を入力してください\n", number);
  for (int i = 0; i < number; i++) {
    printf("height[%d] : ", i);
    scanf("%d", &height[i]);
  }
  //maxofの呼び出しで指定したheightはポインタであるため要素数を知らない。
  printf("最大値は%dです\n", maxof(height, number));
  free(height);
  return 0;
}