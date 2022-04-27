// 再度
#include <stdio.h>
#include <stdlib.h>

static int *buff;

static void __mergesort(int a[], int left, int right)
{
  if (left < right) {
    int center = (left + right) / 2;
    int p = 0;
    int i;
    int j = 0;
    int k = left;

    __mergesort(a, left, center);
    __mergesort(a, center + 1, right);

    // ここまで到達した時点でaは前半部と後半部がそれぞれソート済みになっている
    // 以下で前半部と後半部をマージする

    for (i = left; i <= center; i++)
      buff[p++] = a[i];
    while (i <= right && j < p)
      a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
    while (j < p)
      a[k++] = buff[j++];
  }
}