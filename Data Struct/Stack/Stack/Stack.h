#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // 栈顶
	int _capacity; // 容量
	int _size;//尺寸
}Stack;

void StackInit(Stack* ps);
void StackCheck(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);

STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);

void TestStack();