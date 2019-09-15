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
		cur = CreatNote(x);
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
	SingleListNote* cur,*next;
	if (sl->head == NULL)
	{
		return;
	}
	cur = sl->head;
	SingleListNote* next = sl->head->next;
	free(cur);
	cur = NULL;
	sl->head = next;
}
void SingleListPopBack(SingleList* sl)
{




}
void SingleListEraseAfter(SingleListNote* pos)
{
	assert(pos);
	SingleListNote* next = pos->next;
	if (next == NULL)
	{

	}
}

SingleListNote* CreatNote(DateType x)
{
	SingleListNote* newNote = (SingleListNote*)malloc(sizeof(SingleListNote));
	newNote->Date = x;
	newNote->next = NULL;
	return newNote;
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
				prev->next = cur->next
			}
			free(cur);

		}
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
	SingleList* sl;
	SingleListInit(&sl);

	SingleListPushback(&sl, 0);
	SingleListPrint(&sl);
}

int main()
{
	testSingleList();
	system("pause");
	return 0;
}