#include"Stack.h"

void StackInit(Stack* ps)
{
	ps->_capacity = 0;
	ps->_top = 0;
	ps->_size = 0;
}

void StackCheck(Stack* ps)
{
	assert(ps);
	if (ps->_size == 0)
	{
		ps->_capacity = 3;
		ps->_a = (STDataType*)malloc(sizeof(STDataType) * ps->_capacity);
	}
	if (ps->_capacity == ps->_size)
	{
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)*(ps->_capacity + 3));
		ps->_capacity = ps->_capacity + 3;
	}
	else
	{
		return;
	}
}

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	StackCheck(ps);
	ps->_a[ps->_size] = x;
	ps->_top = ps->_a[ps->_size];
	ps->_size++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->_size == 0)
	{
		return;
	}
	ps->_size--;
	ps->_top = ps->_a[ps->_size];
}

STDataType StackTop(Stack* ps)
{
	if (ps->_size == 0)
	{
		return 0;
	}
	return ps->_top;
}
int StackEmpty(Stack* ps)
{
	if (ps->_size == ps->_capacity)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int StackSize(Stack* ps)
{
	return ps->_size;
}

void TestStack()
{
	Stack ps;

	StackInit(&ps);

	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackPush(&ps, 5);
	StackPop(&ps);

	printf("%d\n", StackTop(&ps));
	printf("%d\n", StackEmpty(&ps));
	printf("%d\n", StackSize(&ps));

	StackDestory(&ps);
}

int main()
{
	TestStack();
	system("pause");
	return 0;
}