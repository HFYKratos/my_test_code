#include"SingleList.h"
//无头单项非循环
void SingleListInit(SingleList* sl)
{
	assert(sl);
	sl->head = NULL;
}

void SingleListDestroy(SingleList* sl)
{
	assert(sl);
	SingleListNote* cur = sl->head;
	while (cur)
	{
		SingleListNote* next = cur->next;
		free(cur);
		cur = next;
	}
	sl->head = NULL;
}
void SingleListPushback(SingleList* sl, DateType x)
{
	assert(sl);
	if (sl->head == NULL)
	{
		sl->head = CreatNote(x);
	}
	else
	{
		SingleListNote* cur = sl->head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = CreatNote(x);
	}
}

void SingleListPushFront(SingleList* sl, DateType x)
{
	assert(sl);
	SingleListNote* cur = sl->head;
	SingleListNote* newNote = CreatNote(x);
	newNote->next = cur;
	sl->head = newNote;
}

void SingleListInsertAfter(SingleListNote* pos, DateType x)
{
	assert(pos);
	SingleListNote* newNote = CreatNote(x);
	SingleListNote* next = pos->next;
	pos->next = newNote;
	newNote->next = next;
}

void SingleListPopFront(SingleList* sl)
{
	assert(sl);
	SingleListNote* cur, *next;
	if (sl->head == NULL)
	{
		return;
	}
	cur = sl->head;
	next = sl->head->next;
	free(cur);
	cur = NULL;
	sl->head = next;
}

void SingleListPopBack(SingleList* sl)
{
	assert(sl);
	SingleListNote* prev = NULL;
	SingleListNote* cur = sl->head;
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
		cur = NULL;
		free(cur);
		if (prev == NULL)
		{
			sl->head = NULL;
		}
		else
		{
			prev->next = NULL;
		}
	}
}

void SingleListEraseAfter(SingleListNote* pos)
{
	assert(pos);
	SingleListNote* next = pos->next;
	if (next == NULL)
	{
		return;
	}
	pos->next = next->next;
	free(next);
	next = NULL;
}

SingleListNote* CreatNote(DateType x)
{
	SingleListNote * node = (SingleListNote*)malloc(sizeof(SingleListNote));
	assert(node);
	node->Date = x;
	node->next = NULL;
	return node;
}


void SingleListRemove(SingleList* sl, DateType x)
{
	assert(sl);
	SingleListNote* cur = sl->head;
	SingleListNote* prev = NULL;
	while (cur)
	{
		if (cur->Date == x)
		{
			if (prev == NULL)
			{
				sl->head = cur->next;
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

DateType SingleListCheck(SingleListNote* sl, DateType x)
{
	assert(sl);
	SingleListNote* cur = sl;
	if (cur)
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

void SingleListRemoveAll(SingleList* sl, DateType x)
{
	assert(sl);
	while (SingleListCheck(sl,x) == 1)
	{
		SingleListRemove(sl, x);
	}
}

void SingleListPrint(SingleList* sl)
{
	assert(sl);
	SingleListNote* cur = sl->head;
	while (cur)
	{
		printf("%d->", cur->Date);
		cur = cur->next;
	}
	printf("\n");
}

void testSingleList()
{
	SingleList sl;
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