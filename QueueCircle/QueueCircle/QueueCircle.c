#include"QueueCircle.h"

Queue* QueueInit(int k)
{
	Queue* pq = (Queue*)malloc(sizeof(Queue));
	pq->capacity = k;
	pq->size = 0;
	pq->front = pq->rear = 0;
	pq->arr = (QUDataType*)malloc(sizeof(QUDataType)*pq->capacity);
	return pq;
}
void QueueDestory(Queue* pq)
{
	if (pq->arr)
	{
		free(pq->arr);
		pq->arr = NULL;
	}
}

void QueuePush(Queue* pq, QUDataType x)
{
	if (pq->size == pq->capacity)
	{
		return;
	}
	if (pq->rear + 1 == pq->capacity)
	{
		pq->arr[pq->rear] = x;
		pq->rear = 0;
		pq->size++;
	}
	else
	{
		pq->arr[pq->rear] = x;
		pq->rear++;
		pq->size++;
	}
}
void QueuePop(Queue* pq)
{
	if (pq->size == 0)
	{
		return;
	}
	if (pq->front + 1 == pq->capacity)
	{
		pq->front = 0;
		pq->size--;
	}
	else
	{
		pq->front++;
		pq->size--;
	}
}
void QueuePrint(Queue* pq)
{
	QUDataType size = pq->size;
	for (int i = 0; i < size; i++)
	{
		printf("%d->", QueueFront(pq));
		QueuePop(pq);
	}
	printf("\n");
}

QUDataType QueueFront(Queue* pq)
{
	if (pq->size == 0)
	{
		return 10086;
	}
	return pq->arr[pq->front];
}
QUDataType QueueBack(Queue* pq)
{
	if (pq->size == 0)
	{
		return 10086;
	}
	if (pq->rear == 0 && pq->front != 0 && pq->size != 0)
	{
		return pq->arr[pq->capacity - 1];
	}
	return pq->arr[pq->rear - 1];
}

int QueueEmpty(Queue* pq)
{
	if (pq->size)
	{
		return 1;
	}
	return 0;
}
int QueueSize(Queue* pq)
{
	return pq->size;
}

void TestQueue()
{
	Queue* pq;
	pq = QueueInit(10);

	QueuePush(pq, 0);
	QueuePush(pq, 1);
	//QueuePrint(&pq);
	
	QueuePush(pq, 3);
	QueuePush(pq, 4);
	//QueuePrint(&pq);
	//QueuePop(&pq);
	QueuePush(pq, 5);
	//QueuePrint(&pq);
	QueuePush(pq, 6);
	QueuePush(pq, 7);
	QueuePush(pq, 8);
	QueuePush(pq, 9);
	QueuePrint(pq);
	QueuePush(pq, 10);
	QueuePrint(pq);
	QueuePush(pq, 10);
	QueuePush(pq, 10);
	QueuePush(pq, 10);
	QueuePush(pq, 10);
	QueuePrint(pq);

	QueueDestory(pq);
}

int main()
{
	TestQueue();
	system("pause");
	return 0;
}