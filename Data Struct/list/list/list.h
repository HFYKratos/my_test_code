#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int DateType;
//有头双向链表
typedef struct ListNode
{
	DateType date;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

typedef struct List
{
	struct ListNode* head;
}List;

void ListInit(List* sl);
void ListDestroy(List* sl);

void ListNodePushback(ListNode* sl, DateType x);
void ListNodePushFront(ListNode* sl, DateType x);
void ListNodeInsertFront(ListNode* pos, DateType x);

void ListNodePopFront(ListNode* sl);
void ListNodePopBack(ListNode* sl);
void ListNodeEraseAfter(ListNode* pos);

ListNode* CreatNote(DateType x);
void ListNodePrint(List* sl);
void ListNodeRemove(ListNode* sl, DateType x);
DateType ListNodeCheck(ListNode* sl, DateType x);
void ListNodeRemoveAll(ListNode* sl, DateType x);