#include <stdio.h>

int flag_a[8];    // 各行に王妃を配置済み
int flag_b[15];   // /対角線に配置済み
int flag_c[15];   // \対角線に配置済み
int pos[8];

void print(void)
{
  for (int i = 0; i < 8; i++) {
    printf("%2d", pos[i]);
  }
  putchar('\n');
}

void set(int i)
{
  for (int j = 0; j < 8; j++) {
    if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7]) {
      pos[i] = j;
      if (i == 7)
        print();
      else {
        flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
        set(i + 1);
        flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
      }
    }
  }
}

int main(void)
{
  set(0);
  return 0;
}