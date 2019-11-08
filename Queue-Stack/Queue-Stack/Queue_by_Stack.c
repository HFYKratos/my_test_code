#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>
#include<assert.h>

typedef int STDataType;
typedef struct MyQueue
{
	STDataType* _a;
	int _head; // Õ»¶¥
	int _capacity; // ÈÝÁ¿
	int _size;//³ß´ç
}MyQueue;

void StackCheck(MyQueue* ps)
{
	assert(ps);
	if (ps->_capacity == ps->_size && ps->_capacity == 0)
	{
		ps->_capacity = 5;
		ps->_a = (STDataType*)malloc(sizeof(STDataType) * ps->_capacity);
	}
	if (ps->_capacity == ps->_size)
	{
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)*(ps->_capacity + 5));
		ps->_capacity = ps->_capacity + 5;
	}
	else
	{
		return;
	}
}

int StackPop(MyQueue* ps)
{
	assert(ps);
	if (ps->_size == 0)
	{
		return 0;
	}
	int val = 0;
	val = ps->_a[ps->_size - 1];
	ps->_size--;
	return val;
}

/** Initialize your data structure here. */

MyQueue* myQueueCreate()
{
	MyQueue* ps = (MyQueue*)malloc(sizeof(MyQueue));
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_size = 0;
	return ps;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x)
{
	assert(obj);
	StackCheck(obj);
	obj->_a[obj->_size] = x;
	obj->_size++;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj)
{
	MyQueue* tmp = myQueueCreate();
	int len = obj->_size;
	int val = len;
	while (len - 1 > 0)
	{
		myQueuePush(tmp, StackPop(obj));
		len--;
	}
	len = val;
	val = StackPop(obj);
	while (len - 1 > 0)
	{
		myQueuePush(obj, StackPop(tmp));
		len--;
	}
	return val;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj)
{
	return obj->_a[0];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj)
{
	if (obj->_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void myQueueFree(MyQueue* obj)
{
	assert(obj);
	if (obj->_a != NULL)
	{
		free(obj->_a);
		obj->_a = NULL;
	}
}

int main()
{
	MyQueue* queue = myQueueCreate();

	myQueueEmpty(queue); // ·µ»Ø false
	
	myQueueFree(queue);
	return 0;
}