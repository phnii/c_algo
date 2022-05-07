#ifndef ___LinkedList
#define ___LinkedList

#include "../chap3/lis8.h" // Member

typedef struct __node {
  Member data;
  struct __node *next;
} Node;

typedef struct {
  Node *head;
  Node *crnt;
} List;

void Initialize(List *list);

Node *Search(List *list, const Member *x);

// 先頭にノードを挿入
void InsertFront(List *list, const Member *x);

// 末尾にノードを挿入
void InsertRear(List *list, const Member *x);

// 先頭ノードを削除
void RemoveFront(List *list);

// 末尾ノードを削除
void RemoveRear(List *list);

// 着目ノードを削除
void RemoveCurrent(List *list);

// 全ノードを削除
void Clear(List *list);

// 着目ノードのデータを表示
void PrintCurrent(const List *list);

// 着目ノードのデータを表示(改行)
void PrintLnCurrent(const List *list);

// 全ノードのデータをリスト順に表示
void Print(const List *list);

void Terminate(List *list);

#endif


