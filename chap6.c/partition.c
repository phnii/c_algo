#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

void partition(int a[], int n)
{
  int pl = 0;
  int pr = n - 1;
  int x = a[n / 2];

  do {
    while (a[pl] < x) pl++;
    while (a[pr] > x) pr--;
    if (pl <= pr) {
      swap(int, a[pl], a[pr]);
      pl++;
      pr--;
    }
  } while (pl <= pr);

  printf("枢軸の値は%dです\n", x);

  puts("枢軸以下のグループ");
  for (int i = 0; i <= pl - 1; i++)
    printf("%d", a[i]);
  putchar('\n');

  if (pl > pr + 1) {
    puts("枢軸と一致するグループ");
    for (int i = pr + 1; i <= pl - 1; i++)
      printf("%d", a[i]);
    putchar('\n');
  }

  puts("枢軸以上のグループ");
  for (int i = pr + 1; i < n; i++)
    printf("%d", a[i]);
  putchar('\n');
}

int main(void)
{
  int nx;

  puts("配列を分割します");
  printf("要素数: ");
  scanf("%d", &nx);
  int *x = calloc(nx, sizeof(int));

  for (int i = 0; i < nx; i++) {
    printf("x[%d]: ", i);
    scanf("%d", &x[i]);
  }

  partition(x, nx);

  free(x);

  return 0;
}