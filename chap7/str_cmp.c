#include <stdio.h>

int str_cmp(const char *s1, const char *s2)
{
  while (*s1 == *s2) {
    if (*s1 == '\0')
      return 0;
    s1++;
    s2++;
  }
  return (unsigned char)*s1 - (unsigned char)*s2;
}

int main(void)
{
  char st[128];

  puts("\"ABCD\"との比較を行います: ");
  puts ("\"XXXX\"で終了します");

  while (1) {
    printf("文字列st : ");
    scanf("%s", st);

    if (str_cmp("XXXX", st) == 0)
      break;
    printf("stc_cmp(\"ABCD\") = %d\n", str_cmp("ABCD", st));
  }
  return 0;
}