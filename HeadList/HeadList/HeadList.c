#include"HeadList.h"

void HeadInit(Head* hp, int* a, int n)
{
	assert(hp && a);
	int i = 0;
	hp->capa = hp->size = 0;
	HeadCheckCapacity(hp, n);
	for (i = 0; i < n; i++)
	{
		hp->a[i] = a[i];
		hp->size++;
	}
	i = (n - 2) / 2;
	while (i >= 0)
	{
		ShiftDown(hp->a, n, i);
		i--;
	}
}

void HeadCheckCapacity(Head* hp,int n)
{
	assert(hp);
	if (hp->size == hp->capa)
	{
		int newCapacity = n;
		if(hp->capa == 0)
		{
			hp->a = (int *)malloc(newCapacity * sizeof(int));
			hp->capa = hp->capa + newCapacity;
		}
		else
		{ 
            hp->a = (int* )realloc(hp->a, (hp->capa + 1) * sizeof(int));
			hp->capa = hp->capa + newCapacity;
		}
		assert(hp->a);
	}
}

void HeadPush(Head* hp, int x)
{
	assert(hp);
	HeadCheckCapacity(hp, 1);
	hp->a[hp->size] = x;
	hp->size++;
	ShiftUp(hp->a, (hp->size - 1));
}

void Swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void HeadPop(Head* hp, int x)
{
	int i = 0;
	int pos;
	for (i = 0; i < hp->size; i++)
	{
		if (hp->a[i] == x)
		{
			pos = i;
			break;
		}
	}
	Swap(&hp->a[pos], &hp->a[hp->size - 1]);
	hp->size--;
	ShiftDown(hp->a, hp->size, pos);
}

void ShiftDown(int* a, int n, int root)
{
	assert(a);
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void ShiftUp(int* a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if ( a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}


void HeadPrintf(Head* hp, int n)
{
	assert(hp);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}

void HeadSort(Head* hp, int n)
{
	assert(hp);
	for (int i = 0; i < n ; i++)
	{
		Swap(&hp->a[0], &hp->a[n - 1 - i]);
		ShiftDown(hp->a, hp->size - 1 - i, 0);
	}
}


void HeadDestory(Head* hp)
{
	free(hp->a);
	hp->a = NULL;
}


void test()
{
	int a[] = { 1,5,3,8,7,6 };
	Head hp;
	int n = sizeof(a) / sizeof(a[0]);

	HeadInit(&hp, a, n);
	HeadPrintf(&hp, n);
	HeadPush(&hp, 10);
	HeadPrintf(&hp, hp.size);
	HeadPop(&hp, 10);
	HeadPrintf(&hp, hp.size);
	HeadSort(&hp, hp.size);
	HeadPrintf(&hp, hp.size);

	HeadDestory(&hp);
}

int main()
{
	test();
	system("pause");
	return 0;
}