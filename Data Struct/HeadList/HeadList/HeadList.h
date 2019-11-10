#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef struct Head
{
	int* a;
	int capa;
	int size;
}Head;

void HeadInit(Head* hp, int* a, int n);
void HeadCheckCapacity(Head* hp, int n);
void HeadPrintf(Head* hp,int n);
void HeadPush(Head* hp, int x);
void HeadPop(Head* hp, int x);

void ShiftUp(int* hp, int child);
void ShiftDown(int* a, int n, int root);
void Swap(int* pa, int* pb);

void HeadDestory(Head* hp);
void HeadSort(Head* hp, int n);
