#pragma once
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include<stdio.h>

typedef int QUDataType;
typedef struct Queue
{
	QUDataType capacity;
	QUDataType size;
	QUDataType front, rear;
	QUDataType *arr;
}Queue;

Queue* QueueInit(int k);
void QueueDestory(Queue* pq);

void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);
void QueuePrint(Queue* pq);

QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);

int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

void TestQueue();