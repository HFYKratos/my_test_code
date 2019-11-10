#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#include<assert.h>


typedef int QUDataType;

typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct
{
	QueueNode* _front; // ¶ÓÍ·
	QueueNode* _rear; // ¶ÓÎ²
} MyStack;

QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->_data = x;
	newNode->_next = NULL;
	return newNode;
}

int QueuePop(MyStack* pq)
{
	assert(pq);
	if (pq->_front == NULL)
	{
		return 0;
	}
	else
	{
		QueueNode* old = pq->_front;
		int val = old->_data;
		pq->_front = pq->_front->_next;
		free(old);
		old = NULL;
		if (pq->_front == NULL)
		{
			pq->_rear = NULL;
		}
		return val;
	}
}

void myStackFree(MyStack* obj)
{
	assert(obj);
	QueueNode* cur = obj->_front;
	QueueNode* next = cur;
	while (next)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
	obj->_front = obj->_rear = NULL;
	cur = NULL;
}
/** Initialize your data structure here. */

MyStack* myStackCreate()
{
	MyStack* newStack = (MyStack*)malloc(sizeof(MyStack));
	newStack->_front = newStack->_rear = NULL;
	return newStack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x)
{
	assert(obj);
	QueueNode* newNode = BuyQueueNode(x);
	if (obj->_rear == NULL)
	{
		obj->_front = obj->_rear = newNode;
	}
	else
	{
		obj->_rear->_next = newNode;
		obj->_rear = newNode;
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj)
{
	assert(obj);
	MyStack* newStack = myStackCreate();
	int val = 0;
	while (obj->_front->_next != NULL)
	{
		myStackPush(newStack, QueuePop(obj));
	}
	val = QueuePop(obj);
	*obj = *newStack;
	myStackFree(newStack);
	return val;
}

/** Get the top element. */
int myStackTop(MyStack* obj)
{
	return obj->_rear->_data;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj)
{
	if (obj->_front != NULL && obj->_rear != NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	MyStack* obj = myStackCreate();
	myStackPush(obj, 1);
	myStackPush(obj, 2);
	myStackPop(obj);
	myStackEmpty(obj);
	return 0;
}