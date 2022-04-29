#include <stdio.h>

int kpm_match(const char txt[], const char pat[])
{
  int pt = 1;
  int pp = 0;
  int skip[1024];

  skip[pt] = 0;
  while (pat[pt] != '\0') {
    if (pat[pt] == pat[pp])
      skip[++pt] = ++pp;
    else if (pp == 0)
      skip[++pt] = pp;
    else
      pp = skip[pp];
  }
  pt = pp = 0;
  while (txt[pt] != '\0' && pat[pp] != '\0') {
    if (txt[pt] == pat[pp]) {
      pt++;
      pp++;
    } else if (pp == 0)
      pt++;
    else
      pp = skip[pp];
  }
  if (pat[pp] == '\0')
    return pt - pp;
    return -1;
}

int main(void)
{
  char s1[256];
  char s2[256];

  puts("KPM法");

  printf("テキスト: ");
  scanf("%s", s1);
  printf("パターン: ");
  scanf("%s", s2);

  int idx = kpm_match(s1, s2);

  if (idx == -1)
    puts("テキスト中にパターンは存在しません");
  else
    // 配列と違って文字列に0文字目はない
    printf("%d文字目にマッチしました\n", idx + 1);
  return 0;
}