#include <stdio.h>

int bf_match(const char txt[], const char pat[])
{
  int pt = 0;
  int pp = 0;

  while (txt[pt] != '\0' && pat[pp] != '\0') {
    if (txt[pt] == pat[pp]) {
      pt++;
      pp++;
    } else {
      // ptはpp回移動しているから-ppして元に戻して1進める
      pt = pt - pp + 1;
      pp = 0;
    }
  }
  if (pat[pp] == '\0')
    return pt - pp;

  return -1;
}

int main(void)
{
  char s1[256];
  char s2[256];

  puts("力まかせ法");

  printf("テキスト: ");
  scanf("%s", s1);
  printf("パターン: ");
  scanf("%s", s2);

  int idx = bf_match(s1, s2);

  if (idx == -1)
    puts("テキスト中にパターンは存在しません");
  else
    // 配列と違って文字列に0文字目はない
    printf("%d文字目にマッチしました\n", idx + 1);
  return 0;
}