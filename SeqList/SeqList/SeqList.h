#define N 100
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
//#include <vld.h>

typedef struct SeqList
{
	int* arr;
	size_t size;
	size_t capacity;
}SeqList;
//初始化和释放
void SeqListInit(SeqList* sl);
void SeqListDestory(SeqList* sl);
//检查存量及扩容
void SeqListCheckCapacity(SeqList* sl);
//增加
void SeqListPushBack(SeqList* sl, int x);
void SeqListPushFront(SeqList* sl, int x);
void SeqListInsert(SeqList* s1, size_t pos, int x);
//删减
void SeqListPopBack(SeqList* sl);
void SeqListPopFront(SeqList* sl);
void SeqListErase(SeqList* sl, size_t pos);
//查找
int SeqListFind(SeqList* sl, int x);
//打印
void SeqListPrint(SeqList* sl);
//大小
size_t SeqListSize(SeqList* sl);
//取值
int SeqListAt(SeqList* sl, size_t pos);
//移动
void SeqListRemoveAll(SeqList* sl, int x);
//排序
void SeqListBubbleSort(SeqList* sl);
//二分查找
int SeqListBinaryFind(SeqList* sl, int x);