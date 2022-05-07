#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char  name[10];
  int   height;
  int   weight;
} Person;


// Person型の名前による比較関数を定義
int npcmp(const Person *x, const Person *y)
{
  return strcmp(x->name, y->name);
}

// 身長昇順
int hpcmp(const Person *x, const Person *y)
{
  return x->height < y->height ? -1 :
         x->height > y->height ? 1: 0;
}

// 身長降順
int wpcmp(const Person *x, const Person *y)
{
  return x->weight < y->weight ? 1 :
         x->weight > y->weight ? -1: 0;
}

void print_person(const Person x[], int no)
{
  for (int i = 0; i < no; i++) {
    printf("%-10s %dcm %dkg\n", x[i].name, x[i].height, x[i].weight);
  }
}

int main(void)
{
  Person x[] = {
    {"Shibata", 170, 52},
    {"Takaoka", 180, 70},
    {"Nangoh", 172, 63},
    {"Sugiyama", 165, 50},
  };

  int nx = sizeof(x) / sizeof(x[0]);

  puts("ソート前");
  print_person(x, nx);

  qsort(x, nx, sizeof(Person), (int (*)(const void *, const void *))npcmp);

  puts("\n名前昇順ソート");
  print_person(x, nx);

  qsort(x, nx, sizeof(Person), (int (*)(const void *, const void *))hpcmp);

  puts("\n身長昇順ソート");
  print_person(x, nx);

  qsort(x, nx, sizeof(Person), (int (*)(const void *, const void *))wpcmp);

  puts("\n体重降順ソート");
  print_person(x, nx);

  return 0;
}
