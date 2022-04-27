#include <stdio.h>
#include <limits.h>

void str_dump(const char *s)
{
  for (; *s != '\0'; s++) {
    printf("%c  %0*X  ", *s, (CHAR_BIT + 3) / 4, *s);
    for (int i = CHAR_BIT - 1; i >= 0; i--)
      putchar(((*s >> i) & 1U) ? '1' : '0');
    putchar('\n');
  }
}

int main(void)
{
  str_dump("Ss");
  return 0;
}