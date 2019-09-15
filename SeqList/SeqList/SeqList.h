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
//��ʼ�����ͷ�
void SeqListInit(SeqList* sl);
void SeqListDestory(SeqList* sl);
//������������
void SeqListCheckCapacity(SeqList* sl);
//����
void SeqListPushBack(SeqList* sl, int x);
void SeqListPushFront(SeqList* sl, int x);
void SeqListInsert(SeqList* s1, size_t pos, int x);
//ɾ��
void SeqListPopBack(SeqList* sl);
void SeqListPopFront(SeqList* sl);
void SeqListErase(SeqList* sl, size_t pos);
//����
int SeqListFind(SeqList* sl, int x);
//��ӡ
void SeqListPrint(SeqList* sl);
//��С
size_t SeqListSize(SeqList* sl);
//ȡֵ
int SeqListAt(SeqList* sl, size_t pos);
//�ƶ�
void SeqListRemoveAll(SeqList* sl, int x);
//����
void SeqListBubbleSort(SeqList* sl);
//���ֲ���
int SeqListBinaryFind(SeqList* sl, int x);