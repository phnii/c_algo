#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

int sort3elem(int x[], int a, int b, int c)
{
  if (x[b] < x[a]) swap(int, x[a], x[b]);
  if (x[c] < x[b]) swap(int, x[c], x[b]);
  if (x[b] < x[a]) swap(int, x[b], x[a]);
  return b;
}

void quick(int a[], int left, int right)
{
  int pl = left;
  int pr = right;
  int m = sort3elem(a, pl, (pl + pr) / 2, pr);
  int x = a[m];

  swap(int, a[m], a[right - 1]);
  pl++;
  pr -= 2;

  do {
    while (a[pl] < x) pl++;
    while (a[pr] > x) pr--;
    if (pl <= pr) {
      swap(int, a[pl], a[pr]);
      pl++;
      pr--;
    }
  } while (pl <= pr); // plとprがすれ違ったところで分割完了

  if (left < pr) quick(a, left, pr);
  if (pl < right) quick(a, pl, right);
}

int main(void)
{
  int nx;

  puts("クイックソート");
  printf("要素数: ");
  scanf("%d", &nx);
  int *x = calloc(nx, sizeof(int));

  for (int i = 0; i < nx; i++) {
    printf("x[%d]: ", i);
    scanf("%d", &x[i]);
  }

  quick(x, 0, nx - 1);

  puts("昇順にソートしました");
  for (int i = 0; i < nx; i++)
    printf("x[%d] = %d\n", i, x[i]);

  free(x);

  return 0;
}