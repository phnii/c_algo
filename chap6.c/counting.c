#include <stdio.h>
#include <stdlib.h>

void counting(int a[], int n, int max)
{
  int *f = calloc(max + 1, sizeof(int));
  int *b = calloc(n, sizeof(int));

  for (int i = 0; i <= max; i++)
    f[i] = 0;
  for (int i = 0; i < n; i++)
    f[a[i]]++;
  for (int i = 1; i <= max; i++)
    f[i] += f[i - 1];
  for (int i = n - 1; i >= 0; i--)
    b[--f[a[i]]] = a[i];
  for (int i = 0; i < n; i++)
    a[i] = b[i];

  free(b);
  free(f);
}

int main(void)
{
  int nx;
  const int max = 100;

  puts("度数ソート");
  printf("要素数: ");
  scanf("%d", &nx);
  int *x = calloc(nx, sizeof(int));

  printf("0 ~ %dの整数を入力してください\n", max);
  for (int i = 0; i < nx; i++) {
    do {
      printf("x[%d] : ", i);
      scanf("%d", &x[i]);
    } while (x[i] < 0 || x[i] > max);
  }

  counting(x, nx, max);

  puts("昇順にソートしました");
  for (int i = 0; i < nx; i++)
    printf("x[%d] = %d\n", i, x[i]);
  
  free(x);

  return 0;
}