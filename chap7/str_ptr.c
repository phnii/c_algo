#include <stdio.h>

int main(void)
{
  char *pt = "1234";
  char ary[] = "1234";
  printf("ポインタptは\"%s\"を指しています\nサイズは%luです\n", pt, sizeof(pt));
  printf("配列aryは%sを指しています\nサイズは%dです\n", ary, (int) sizeof(ary));

  puts("forによる文字配列の出力");
  for (char *s = &ary; *s != '\0'; s++) {
    printf("%c", *s);
  }
  return 0;

}