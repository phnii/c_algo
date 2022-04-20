#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key)
{
  int ptl = 0;
  int ptr = n - 1;
  int ptc;

  while(1) {
    ptc = (ptl + ptr) / 2;
    if (a[ptc] == key)
      return ptc;
    else if (a[ptc] < key) {
      ptl = ptc + 1;
    } else {
      ptr = ptc - 1;
    }
    if (ptr < ptl)
      return -1;
  }
}

int main(void)
{
  int nx, ky;
  puts("2分探索");
  printf("要素数 : ");
  scanf("%d", &nx);
  int *x = calloc(nx, sizeof(int));
  printf("昇順に入力してください\n"); 
  for (int i = 1; i < nx; i++) {
    do {
      printf("x[%d] : ", i);
      scanf("%d", &x[i]);
    } while (x[i] < x[i - 1]);
  }
  printf("探す値: ");
  scanf("%d", &ky);

  int idx = bin_search(x, nx, ky);

  if (idx == -1)
    puts("探索に失敗しました");
  else
    printf("%dはx[%d]にあります\n", ky, idx);
  free(x);
  return 0;
}