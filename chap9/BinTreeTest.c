#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../chap3/lis8.h"
#include "../chap3/lis9.c"
#include "BinTree.h"
#include "BinTree.c"

typedef enum {
  TERMINATE, ADD, REMOVE, SEARCH, PRINT
} Menu;

Menu SelectMenu(void)
{
  int ch;

  do {
    printf("\n1.Add 2.Remove 3.Search 4.Print 0.Exit : ");
    scanf("%d", &ch);
  } while (ch < TERMINATE || ch > PRINT);
  return (Menu)ch;
}

int main(void)
{
  Menu menu;
  BinNode *root = NULL;

  do {
    Member x;
    BinNode *temp;

    switch (menu = SelectMenu()) {
      case ADD:
        x = ScanMember("挿入", MEMBER_NO | MEMBER_NAME);
        root = Add(root, &x);
        break;
      case REMOVE:
        x = ScanMember("削除", MEMBER_NO);
        Remove(&root, &x);
        break;
      case SEARCH:
        x = ScanMember("探索", MEMBER_NO);
        if ((temp = Search(root, &x)) != NULL)
          PrintLnMember(&temp->data);
        break;
      case PRINT:
        puts("一覧表示");
        PrintTree(root);
        break;
    }
  } while (menu != TERMINATE);

  FreeTree(root);

  return 0;
}
