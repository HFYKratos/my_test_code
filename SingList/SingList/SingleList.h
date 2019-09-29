#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
typedef int DateType;

typedef struct SingleListNote
{
	DateType Date;
	struct SingleList* next;
}SingleListNote;

typedef struct SingleList
{
	SingleListNote* head;
}SingleList;

void SingleListInit(SingleList* sl);
void SingleListDestroy(SingleList* sl);

void SingleListPushback(SingleList* sl, DateType x);
void SingleListPushFront(SingleList* sl, DateType x);
void SingleListInsertAfter(SingleListNote* pos, DateType x);

void SingleListPopFront(SingleList* sl);
void SingleListPopBack(SingleList* sl);
void SingleListEraseAfter(SingleListNote* pos);

SingleListNote* CreatNote(DateType x);
void SingleListPrint(SingleList* sl);
void SingleListRemove(SingleList* sl, DateType x);
DateType SingleListCheck(SingleListNote* sl, DateType x);
void SingleListRemoveAll(SingleList* sl, DateType x);
