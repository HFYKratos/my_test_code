#include"Stack.h"

void StackInit(Stack* ps)
{
	ps->_capacity = 10;
	ps->_a = (Stack*)malloc(sizeof(Stack)*ps->_capacity);
	ps->_top = 0;
}

void StackCheck(Stack* ps)
{
	if (ps->_capacity == 0)
	{

	}
}

void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);

STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);

void TestStack();