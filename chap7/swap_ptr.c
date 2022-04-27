#include <stdio.h>

void swap_ptr(char *x, char *y)
{
  char *tmp = x;
  x = y;
  y = tmp;
}

int main(void)
{
  char *s1 = "ABCD";
  char *s2 = "EFGH";

  printf("ポインタs1は\"%s\"を指しています\n", s1);
  printf("ポインタs2は\"%s\"を指しています\n", s2);

  swap_ptr(s1, s2);

  puts("\nポインタs1とs2の値を交換しました");

  printf("ポインタs1は\"%s\"を指しています\n", s1);
  printf("ポインタs2は\"%s\"を指しています\n", s2);

  return 0;
}