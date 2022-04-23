#include <stdio.h>
#include "lis1.h"
#include "lis1.c"

int main(void)
{
  IntStack s;

  if (Initialize(&s, 64)) {
    puts("スタック生成に失敗しました");
    return 1;
  }

  while (1) {
    int menu, x;

    printf("現在のデータ数 : %d / %d\n", Size(&s), Capacity(&s));
    printf("1.Push 2.Pop 3.Peak 4.View 0.Exit :");
    scanf("%d", &menu);

    if (menu == 0) break;

    switch (menu) {
      case 1:
        printf("データ : ");
        scanf("%d", &x);
        if (Push(&s, x) == -1)
          puts("\aエラー： Pushに失敗しました");
        break;
      case 2:
        if (Pop(&s, &x) == -1)
          puts("\aエラー：Popに失敗しました");
        else
          printf("Popしたデータは%dです\n", x);
        break;
      case 3:
        if (Peak(&s, &x) == -1)
          puts("\aエラー：Peakに失敗しました");
        else
          printf("Peakしたデータは%dです\n", x);
      case 4:
        Print(&s);
        break;
    }
  }
  Terminate(&s);
  return 0;
}