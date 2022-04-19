#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

void ary_reverse(int a[], int n)
{
  for (int i = 0; i < n / 2; i++)
    swap(int, a[i], a[n - i - 1]);
}

int main(void)
{
  int nx;
  printf("要素数: ");
  scanf("%d", &nx);
  int *x = calloc(nx, sizeof(int));

  for (int j = 0; j < nx; j++) {
    printf("x[%d] : ", j);
    scanf("%d", &x[j]);
  }
  ary_reverse(x, nx);
  printf("要素の並びを反転しました\n");
  for (int i = 0; i < nx; i++)
    printf("x[%d] = %d\n", i, x[i]);
  free(x);
  return 0;
}