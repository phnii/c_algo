#include <stdio.h>
#include <stdlib.h>

void shell(int a[], int n)
{
  for (int h = n / 2; h > 0; h /= 2) {
    // iが一つ増えるとソートするグループが変わる
    for (int i = h; i < n; i++) {
      int tmp = a[i];
      int j;
      for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
        a[j + h] = a[j];
      a[j + h] = tmp;
    }
  }
}

int main(void)
{
  int nx;

  puts("シェルソート");
  printf("要素数: ");
  scanf("%d", &nx);
  int *x = calloc(nx, sizeof(int));

  for (int i = 0; i < nx; i++) {
    printf("x[%d] : ", i);
    scanf("%d", &x[i]);
  }

  shell(x, nx);

  puts("昇順にソートしました");
  for (int i = 0; i < nx; i++) {
    printf("x[%d] = %d\n", i, x[i]);
  }
  free(x);

  return 0;
}

