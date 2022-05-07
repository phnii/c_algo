#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

void selection(int a[], int n, int *cnt)
{
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[min])
        min = j;
    swap(int, a[i], a[min]);
    (*(cnt))++;
    }
  }
}

int main(void)
{
  int nx;
  int cnt = 0;
  printf("要素数: ");
  scanf("%d", &nx);
  int *x = calloc(nx, sizeof(int));

  for (int i = 0; i < nx; i++) {
    printf("x[%d] = ", i);
    scanf("%d", &x[i]);
  }

  selection(x, nx, &cnt);
  puts("ソートしました");
  printf("交換回数は%dです\n", cnt);

  for (int i = 0; i < nx; i++) {
    printf("x[%d] = %d\n", i, x[i]);
  }
  free(x);

  return 0;
}