#include <stdio.h>

int str_chr(const char *s, int c)
{
  int i = 0;

  c = (char) c;
  while (s[i] != c) {
    if (s[i] == '\0')
      return -1;
    i++;
  }
  return i;
}

int main(void)
{
  char str[128];
  char tmp[128];
  int ch;
  int idx;

  printf("文字列 : ");
  scanf("%s", str);

  printf("探す文字 : ");
  scanf("%s", tmp);
  ch = tmp[0];

  if ((idx = str_chr(str, ch)) == -1)
    printf("文字'%c'は文字列中に存在しません\n", ch);
  else
    printf("文字%cは%d文字目に存在します\n", ch, idx + 1);
  return 0;
}