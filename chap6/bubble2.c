#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

void bubble(int a[], int n)
{
  for (int i = 0; i < n - 1; i++) {
    // a[0] から a[i]までをソート済みにする
    // あるパスの開始から終了まで一度も交換が生じなかったら、その時点でソート済みと判定して終了
    int exchg = 0;
    for (int j = n - 1; j > i; j--) {
      if (a[j - 1] > a[j]) {
        swap(int, a[j - 1], a[j]);
        exchg++;
      }
    }
    if (exchg == 0)
      break;
  }
}

int main(void)
{
  // 実行時に要素数を指定して配列を作成
  int nx;
  puts("単純交換ソート");
  printf("要素数 : ");
  scanf("%d", &nx);
  int *x = calloc(nx, sizeof(int));

  for (int i = 0; i < nx; i++) {
    printf("x[%d] :", i);
    scanf("%d", &x[i]);
  }
  bubble(x, nx);

  puts("昇順にソートしました");
  for (int i = 0; i < nx; i++)
    printf("x[%d] = %d\n", i, x[i]);
  free(x);

  return 0;
}