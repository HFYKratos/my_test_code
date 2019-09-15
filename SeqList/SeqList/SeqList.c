#include"SeqList.h"

void SeqListInit(SeqList* sl)
{
	sl->arr = NULL;
	sl->capacity = 0;
	sl->size = 0;
}
void SeqListCheckCapacity(SeqList* sl)
{
	assert(sl);
	if (sl->size == sl->capacity)
	{
		size_t newCapacity = ((sl->capacity == 0 )? 5 : 2 * sl->capacity);
		sl->arr = (int *)realloc(sl->arr, newCapacity * sizeof(int));//增容
		assert(sl->arr);                               //申请失败
		sl->capacity = newCapacity;
	}
}
void SeqListDestory(SeqList* sl)
{
	assert(sl);
	if (sl->arr)//如果不为空则清空
	{
		free(sl->arr);
		sl->arr = NULL;
		sl->capacity = sl->size = 0;
	}
}
void SeqListPushBack(SeqList* sl, int x)//尾插
{
	assert(sl);
	SeqListCheckCapacity(sl);
	sl->arr[sl->size] = x;
	++sl->size;
}
void SeqListPushFront(SeqList* sl, int x)//头插
{
	assert(sl);
	SeqListCheckCapacity(sl);
	//移动元素 从后向前
	size_t end = sl->size;
	while (end > 0)
	{
		sl->arr[end] = sl->arr[end - 1];
		--end;
	}
	sl->arr[0] = x;
	++sl->size;
}
void SeqListInsert(SeqList* sl, size_t pos, int x)
{
	assert(sl && pos <= sl->size);
	SeqListCheckCapacity(sl);
	size_t end = sl->size;
	while (end > pos)
	{
		sl->arr[end] = sl->arr[end - 1];
		--end;
	}
	sl->arr[pos] = x;
	++sl->size;
}

void SeqListPopBack(SeqList* sl)
{
	assert(sl);
	if (sl->size != 0)
	{
		--sl->size;
	}
}
void SeqListPopFront(SeqList* sl)
{
	assert(sl);
	if (sl->size > 0)
	{
		size_t start = 0;
		while (start < sl->size - 1)
		{
			sl->arr[start] = sl->arr[start + 1];
			++start;
		}
		--sl->size;
	}
}
void SeqListErase(SeqList* sl, size_t pos)//删除当前数据
{
	assert(sl && pos <sl->size);
	size_t start = pos + 1;
	while (start < sl->size)
	{
		sl->arr[start - 1] = sl->arr[start];
		++start;
	}
	--sl->size;
}

void SeqListPrint(SeqList* sl)
{
	assert(sl);
	for (size_t i = 0 ; i < sl->size ; ++i)
	{
		printf("%d ", sl->arr[i]);
	}
	printf("\n");
}

size_t SeqListSize(SeqList* sl)
{
	return sl->size;
}

int SeqListFind(SeqList* sl, int x)//查找
{
	assert(sl);
	for (size_t i = 0; i < sl->size; ++i)
	{
		if (sl->arr[i] == x)
			return i;
	}
	return -1;
}

int SeqListAt(SeqList* sl, size_t pos)
{
	assert(sl && pos < sl->size);
	return sl->arr[pos];
}

void SeqListRemoveAll(SeqList* sl, int x)
{
	assert(sl);
	size_t index = 0;
	for (size_t i = 0; i < sl->size; ++i)
	{
		if (sl->arr[i] != x)
		{
			sl->arr[index] = sl->arr[i];
			++index;
		}
	}
	sl->size = index;
}
void SeqListBubbleSort(SeqList* sl)
{
	assert(sl);
	size_t cou = 0;
	size_t end = sl->size;
	//升序  
	while (end > 1)
	{
		//单趟排序
		cou = 0;
		for (size_t i = 0; i < end; ++i)
		{
			if (sl->arr[i - 1] > sl->arr[i])
			{
				int tmp = sl->arr[i - 1];
				sl->arr[i - 1] = sl->arr[i];
				sl->arr[i] = tmp;
				cou++;
			}
		}
		if (cou == 0)
		{
			break;
		}
		--end;
	}
}
int SeqListBinaryFind(SeqList* sl, int x)
{
	assert(sl);
	size_t start = 0;
	size_t end = sl->size - 1;
	while (start <= end)
	{
		size_t mid = start + (end - start) / 2;
		if (sl->arr[mid] == x)
		{
			return mid;
		}
		else if (sl->arr[mid] > x)
		{
			end = mid - 1;
		}
		else if (sl->arr[mid] < x)
		{
			start = mid + 1;
		}
	}
	return -1;
}

void testSeqList()
{
	SeqList s;
	SeqListInit(&s);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);

	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 5);
	SeqListPrint(&s);

	SeqListInsert(&s, 2, 3);
	SeqListInsert(&s, 2, 6);
	SeqListPrint(&s);

	//SeqListRemoveAll(&s, 1);
	//SeqListPopBack(&s);
	//SeqListPopFront(&s);
	//SeqListErase(&s, 0);
	SeqListBubbleSort(&s);
	SeqListPrint(&s);
	printf("%d\n", SeqListBinaryFind(&s, 5));

	//printf("第%d元素为：%u\n", 2, SeqListAt(&s, 2));
	printf("全部元素个数为：%u个\n", SeqListSize(&s));
	SeqListDestory(&s);
}

int main()
{
	testSeqList();
	system("pause");
	return 0;
}