#include"list.h"

void ListInit(list** sl)
{
	assert(sl);
	(*sl) = CreatNote(0);
	(*sl)->prev = (*sl);
	(*sl)->next = (*sl);
	(*sl)->date = 0;
}
list* CreatNote(DateType x)
{
	list* newNode = (list* )malloc(sizeof(list));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}
	newNode->date = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void listPushFront(list* sl, DateType x)
{
	assert(sl);
	list* newNode = CreatNote(x);
	list* prev = sl->prev;
	prev->next = newNode;
	newNode->next = sl;
	sl->prev = newNode;
	newNode->prev = prev;
}

void ListPushback(list* sl, DateType x)
{
	assert(sl);
	list* newNode = CreatNote(x);
	list* tail = sl;
	while (sl != tail->next)
	{
		tail = tail->next;
	}
}

void listInsertFront(list* pos, DateType x)
{
	assert(pos);
	list* prev = pos->prev;
	list* newNode = CreatNote(x);
	prev->next = newNode;
	newNode->next = pos;
	newNode->prev = prev;
	pos->prev = newNode;
}

void listPopFront(list* sl) 
{
	assert(sl);
	list* next, *newNode;
	if (sl == NULL)
	{

	}
}

void listPrint(list* sl)
{
	assert(sl);
	list* cur = sl;
	if (sl == NULL)
	{
		printf("NULL\n");
		return;
	}
	while (sl != cur->next)
	{
		printf("%d -> ", cur->date);
		cur = cur->next;
	}
	printf("%d -> %d\n", cur->date, sl->date);
}

void ListDestroy(list** sl) 
{
	assert(sl);
	list* cur1 = (*sl)->next;
	list* cur2 = NULL;
	while ((*sl) != cur1)
	{
		cur2 = cur1->next;
		free(cur1);
		cur1 = cur2;
	}
	free((*sl));
	(*sl) = NULL;
}


void testlist()
{
	list* sl;
	ListInit(&sl);

	ListPushback(&sl, 1);
	listPrint(&sl);

	ListDestroy(&sl);
}
int main()
{
	testlist();
	system("pause");
	return 0;
}