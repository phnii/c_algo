#include <stdio.h>

int main(void)
{
  char st1[8] = {'A', 'B', 'C', '\0'};
  char st2[8] = "EFGH";

  printf("文字列stには(%s)が格納されています\n", st1);
  printf("文字列stには(%s)が格納されています\n", st2);
  return 0;
}