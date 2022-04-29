#include <stdio.h>
#include <string.h>

int main(void)
{
  char st[128];

  puts("\"STRING\"の先頭3文字と比較します: ");
  puts("\"XXXX\"で終了します");

  while (1) {
    printf("文字列: ");
    scanf("%s", st);

    if (strncmp("XXXX", st, 3) == 0)
      break;
    printf("strncmp(\"STRING\", %s, 3) == %d\n", st, strncasecmp("STRING", st, 3));
  }
  return 0;
}