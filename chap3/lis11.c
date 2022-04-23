#include <stdio.h>
#include <stdlib.h>
#include "lis8.h"
#include "lis10.h"

static int hash(int key, int size)
{
  return key % size;
}

static void SetNode(Node *n, const Member *x, const Node *next)
{
  n->data = *x;
  n->next = next;
}

int Initialize(ChainHash *h, int size)
{
  if ((h->table = calloc(size, sizeof(Node *))) == NULL) {
    h->size = 0;
    return 0;
  }
  h->size = size;
  for (int i = 0; i < size; i++) {
    h->table[i] = NULL;
  }

  return 1;
}

Node *Search(const ChainHash *h, const Member *x)
{
  int key = hash(x->no, h->size);
  Node *p = h->table[key];

  while (p != NULL) {
    if (p->data.no == x->no)
      return p;
    p = p->next;
  }
  return NULL;
}

int Add(ChainHash *h, const Member *x)
{
  int key = hash(x->no, h->size);
  Node *p = h->table[key];
  Node *temp;

  while (p != NULL) {
    if (p->data.no == x->no)
      return 1;
    p = p->next;
  }
  if ((temp = calloc(1, sizeof(Node))) == NULL)
    return 2;
  SetNode(temp, x, h->table[key]);
  h->table[key] = temp;

  return 0;
}

int main(void)
{
  puts("hello man!");
  return 1;
}