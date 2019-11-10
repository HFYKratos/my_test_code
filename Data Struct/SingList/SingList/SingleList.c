#include"SingleList.h"
//无头单项非循环
void SingleListInit(SingleListNode* sl)
{
	assert(sl);
	sl->next = NULL;
}

void SingleListDestroy(SingleListNode* sl)
{
	assert(sl);
	SingleListNode* cur = sl->next;
	while (cur)
	{
		SingleListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	sl->next = NULL;
}
void SingleListPushback(SingleListNode* sl, DateType x)
{
	assert(sl);
	if (sl->next == NULL)
	{
		sl->next = CreatNote(x);
	}
	else
	{
		SingleListNode* cur = sl->next;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = CreatNote(x);
	}
}

void SingleListPushFront(SingleListNode* sl, DateType x)
{
	assert(sl);
	SingleListNode* cur = sl->next;
	SingleListNode* newNote = CreatNote(x);
	newNote->next = cur;
	sl->next = newNote;
}

void SingleListInsertAfter(SingleListNode* pos, DateType x)
{
	assert(pos);
	SingleListNode* newNote = CreatNote(x);
	SingleListNode* next = pos->next;
	pos->next = newNote;
	newNote->next = next;
}

void SingleListPopFront(SingleListNode* sl)
{
	assert(sl);
	SingleListNode* cur, *next;
	if (sl->next == NULL)
	{
		return;
	}
	cur = sl->next;
	next = cur->next;
	free(cur);
	cur = NULL;
	sl->next = next;
}

void SingleListPopBack(SingleListNode* sl)
{
	assert(sl);
	SingleListNode* prev = NULL;
	SingleListNode* cur = sl->next;
	if (cur == NULL)
	{
		return;
	}
	else
	{
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;	
		}
		free(cur);
		cur = NULL;
		if (prev == NULL)
		{
			sl->next = NULL;
		}
		else
		{
			prev->next = NULL;
		}
	}
}

void SingleListEraseAfter(SingleListNode* pos)
{
	assert(pos);
	SingleListNode* next = pos->next;
	if (next == NULL)
	{
		return;
	}
	pos->next = next->next;
	free(next);
	next = NULL;
}

SingleListNode* CreatNote(DateType x)
{
	SingleListNode* node = (SingleListNode*)malloc(sizeof(SingleListNode));
	assert(node);
	node->Date = x;
	node->next = NULL;
	return node;
}


void SingleListRemove(SingleListNode* sl, DateType x)
{
	assert(sl);
	SingleListNode* cur = sl->next;
	SingleListNode* prev = NULL;
	while (cur)
	{
		if (cur->Date == x)
		{
			if (prev == NULL)
			{
				sl->next = cur->next;
			}
			else
			{
				prev->next = cur->next;
			}
			free(cur);
			cur = NULL;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

DateType SingleListCheck(SingleListNode* sl, DateType x)
{
	assert(sl);
	SingleListNode* cur = sl->next;
	while (cur)
	{
		if (cur->Date == x)
		{
			return 1;
		}
		else
		{
			cur = cur->next;
		}
	}
	return 0;
}

void SingleListRemoveAll(SingleListNode* sl, DateType x)
{
	assert(sl);
	while (SingleListCheck(sl,x) == 1)
	{
		SingleListRemove(sl, x);
	}
}

void SingleListPrint(SingleListNode* sl)
{
	assert(sl);
	SingleListNode* cur = sl->next;
	while (cur)
	{
		printf("%d->", cur->Date);
		cur = cur->next;
	}
	printf("\n");
}

void testSingleList()
{
	SingleListNode sl;
	SingleListInit(&sl);

	SingleListPushback(&sl, 1);
	SingleListPushFront(&sl, 2);
	SingleListPushFront(&sl, 3);
	SingleListPushback(&sl, 3);
	SingleListPrint(&sl);

	//SingleListPopBack(&sl);
	//SingleListPopFront(&sl);
	SingleListRemoveAll(&sl, 3);
	SingleListPrint(&sl);
	SingleListDestroy(&sl);
}

int main()
{
	testSingleList();
	system("pause");
	return 0;
}