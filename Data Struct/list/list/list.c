#include"list.h"

void ListInit(List* sl)
{
	assert(sl);
	ListNode* head = CreatNote(-1);
	head->next = head;
	head->prev = head;
	sl->head = head;
}
ListNode* CreatNote(DateType x)
{
	ListNode* newNode = (ListNode* )malloc(sizeof(ListNode));
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

void ListNodePushFront(ListNode* sl, DateType x)
{
	assert(sl);
	ListNode* newNode = CreatNote(x);
	ListNode* next = sl->next;
	newNode->next = next;
	sl->next = newNode;
	newNode->prev = sl;
	next->prev = newNode;
}

void ListNodePushback(ListNode* sl, DateType x)
{
	assert(sl);
	ListNode* tail = sl->prev;
	ListNode* newNode = CreatNote(x);
	if (tail == sl)
	{
		sl->next = newNode;
		newNode->next = sl;
		newNode->prev = sl;
		sl->prev = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->next = sl;
		newNode->prev = tail;
		sl->prev = newNode;
	}
}

void ListNodeInsertFront(ListNode* pos, DateType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newNode = CreatNote(x);
	prev->next = newNode;
	newNode->next = pos;
	newNode->prev = prev;
	pos->prev = newNode;
}

void ListNodePopFront(ListNode* sl) 
{
	assert(sl);
	if (sl->next == sl->prev)
	{
		return;
	}
	else
	{
		ListNode* prev = sl;
		ListNode* cur = sl->next;
		prev->next = cur->next;
		cur->next->prev = prev;
		free(cur);
		cur = NULL;
	}
}

void ListNodePopBack(ListNode* sl)
{
	assert(sl);
	if (sl->next == sl->prev)
	{
		return;
	}
	ListNode* tail = sl->prev;
	tail->prev->next = sl;
	sl->prev = tail->prev;
	free(tail);
	tail = NULL;
}

void ListNodeEraseAfter(ListNode* pos)
{
	assert(pos);
	if (pos->next == pos->prev)
	{
		return;
	}
	ListNode* next = pos->next;
	pos->next = next->next;
	next->next->prev = pos;
	free(next);
	next = NULL;
}

DateType ListNodeCheck(ListNode* sl, DateType x)
{
	assert(sl);
	if (sl->next == sl->prev)
	{
		return 0;
	}
	ListNode* cur = sl->next;
	while (cur->next != sl)
	{
		if (cur->date == x)
		{
			return 1;
		}
		cur = cur->next;
	}
	if (cur->date == x)
	{
		return 1;
	}
	return 0;
}

void ListNodeRemove(ListNode* sl, DateType x)
{
	assert(sl);
	if (sl->next == sl->prev)
	{
		return;
	}
	DateType ret = ListNodeCheck(sl, x);
	if (ret)
	{
		ListNode* cur = sl->next;
		ListNode* prev = cur->prev;
		while (cur != sl)
		{
			if (cur->date == x)
			{
				prev->next = cur->next;
				cur->next->prev = prev;
				free(cur);
				cur = NULL;
				break;
			}
			else
			{
				cur = cur->next;
				prev = cur->prev;
			}
		}
	}
	else
	{
		return;
	}
}

void ListNodeRemoveAll(ListNode* sl, DateType x)
{
	assert(sl);
	if (sl->next == sl->prev)
	{
		return;
	}
	while (ListNodeCheck(sl, x))
	{
		ListNodeRemove(sl, x);
	}
}

void ListNodePrint(List* sl)
{
	assert(sl);
	ListNode* cur = sl->head;
	if (sl->head == cur->next)
	{
		printf("NULL\n");
		return;
	}
	while (sl->head != cur->next)
	{
		printf("%d -> ", cur->next->date);
		cur = cur->next;
	}
	printf("\n");
}

void ListDestroy(List* sl) 
{
	assert(sl);
	ListNode* cur1 = sl->head->next;
	ListNode* cur2 = NULL;
	while (sl->head != cur1)
	{
		cur2 = cur1->next;
		free(cur1);
		cur1 = cur2;
	}
	free(sl->head);
	sl->head = NULL;
}


void testListNode()
{
	List sl;
	ListInit(&sl);

	ListNodePrint(&sl);
	ListNodePushback((&sl)->head, 1);
	ListNodePrint(&sl);
	ListNodePushFront((&sl)->head, 2);
	ListNodePushFront((&sl)->head, 3);
	ListNodePushFront((&sl)->head, 4);
	ListNodePrint(&sl);
	ListNodePopBack((&sl)->head);
	ListNodePrint(&sl);
	ListNodePopFront((&sl)->head);
	ListNodePrint(&sl);
	ListNodePushback((&sl)->head, 1);
	ListNodePushback((&sl)->head, 1);
	ListNodePushback((&sl)->head, 1);
	ListNodePushback((&sl)->head, 1);
	ListNodePushback((&sl)->head, 1);
	ListNodePrint(&sl);
	ListNodeRemoveAll((&sl)->head, 1);
	ListNodePrint(&sl);

	ListDestroy(&sl);
}
int main()
{
	testListNode();
	system("pause");
	return 0;
}