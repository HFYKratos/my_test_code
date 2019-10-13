#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
typedef int DateType;

typedef struct SingleListNode
{
	DateType Date;
	struct SingleListNode* next;
}SingleListNode;

void SingleListInit(SingleListNode* sl);
void SingleListDestroy(SingleListNode* sl);

void SingleListPushback(SingleListNode* sl, DateType x);
void SingleListPushFront(SingleListNode* sl, DateType x);
void SingleListInsertAfter(SingleListNode* pos, DateType x);

void SingleListPopFront(SingleListNode* sl);
void SingleListPopBack(SingleListNode* sl);
void SingleListEraseAfter(SingleListNode* pos);

SingleListNode* CreatNote(DateType x);
void SingleListPrint(SingleListNode* sl);
void SingleListRemove(SingleListNode* sl, DateType x);
DateType SingleListCheck(SingleListNode* sl, DateType x);
void SingleListRemoveAll(SingleListNode* sl, DateType x);
