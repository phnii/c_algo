#ifndef __BinTree
#define __BinTree
#include "../chap3/lis8.h"

typedef struct __bnode {
  Member    data;
  struct __bnode *left;
  struct __bnode *right;
} BinNode;

BinNode *Search(BinNode *p, const Member *x);

BinNode *Add(BinNode *p, const Member *x);

int Remove(BinNode **root, const Member *x);

void PrintTree(const BinNode* p);

void (FreeTree(BinNode* p));

#endif