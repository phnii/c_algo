#include <stdio.h>
#include "IntQue.h"
#include "IntQue.c"

int main(void)
{
  IntQueue que;

  if (Initialize(&que, 64) == -1) {
    puts("キューの生成に失敗しました");
    return 1;
  }
  while (1) {
    int m, x;

    printf("現在のデータ数: %d / %d\n", Size(&que), Capacity(&que));
    printf("1.EnQue 2.DeQue 3.Peak 4.Print 0.Exit : \n");
    scanf("%d", &m);

    if (m == 0)
      break;
    
    switch (m) {
      case 1:
        printf("データ: ");
        scanf("%d", &x);
        if (Enque(&que, x) == -1)
          puts("\aエラー：EnQueに失敗しました");
        break;
      case 2:
        if (Deque(&que, &x) == -1)
          puts("\aエラー：DeQueに失敗しました");
        else
          printf("デキューしたデータは%dです\n", x);
        break;
      case 3:
        if (Peak(&que, &x) == -1)
          puts("\aエラー：Peakに失敗しました");
        else
          printf("Peakしたデータは%dです\n", x);
        break;
      case 4:
        Print(&que);
        break;
    }
  }
  Terminate(&que);
  return 0;
}