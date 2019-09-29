#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int DateType;
//有头双向链表
typedef struct listNode
{
	DateType date;
	struct listNode* next;
	struct listNode* prev;
}list;

void ListInit(list** sl);
void ListDestroy(list** sl);

void ListPushback(list* sl, DateType x);
void listPushFront(list* sl, DateType x);
void listInsertAfter(list* pos, DateType x);

void listPopFront(list* sl);
void listPopBack(list* sl);
void listEraseAfter(list* pos);

list* CreatNote(DateType x);
void listPrint(list* sl);
void listRemove(list* sl, DateType x);
DateType listCheck(list* sl, DateType x);
void listRemoveAll(list* sl, DateType x);



