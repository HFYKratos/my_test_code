#include"Queue.h"

void QueueInit(Queue* pq)
{
	pq->_front = pq->_rear = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	QueueNode* next = cur;
	while (next)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = pq->_rear = NULL;
	cur = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->_data = x;
	newNode->_next = NULL;
	return newNode;
}

void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	QueueNode* newNode = BuyQueueNode(x);
	if (pq->_rear == NULL)
	{
		pq->_front = pq->_rear = newNode;
	}
	else
	{
		pq->_rear->_next = newNode;
		pq->_rear = newNode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	if (pq->_front == NULL)
	{
		return;
	}
	else
	{
		QueueNode* old = pq->_front;
		pq->_front = pq->_front->_next;
		free(old);
		old = NULL;
		if (pq->_front == NULL)
		{
			pq->_rear = NULL;
		}
	}
}

void QueuePrint(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	while (cur)
	{
		printf("%d -> ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

QUDataType QueueFront(Queue* pq)
{
	assert(pq);
	if (pq->_front != NULL)
	{
		return pq->_front->_data;
	}
	else
	{
		return 0;
	}
}

QUDataType QueueBack(Queue* pq)
{
	assert(pq);
	if (pq->_rear != NULL)
	{
		return pq->_rear->_data;
	}
	else
	{
		return 0;
	}
}

int QueueEmpty(Queue* pq)
{
	if (pq->_front != NULL && pq->_rear == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int QueueSize(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}

void TestQueue()
{
	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 2);
	QueuePush(&pq, 3);
	QueuePush(&pq, 4);
	QueuePush(&pq, 5);
	QueuePush(&pq, 6);
	QueuePrint(&pq);

	QueuePop(&pq);
	QueuePrint(&pq);

	printf("%d ", QueueFront(&pq));
	printf("\n");
	printf("%d ", QueueBack(&pq));
	printf("\n"); 
	printf("%d ", QueueSize(&pq));
	printf("\n");
	printf("%d ", QueueEmpty(&pq));
	printf("\n");

	QueueDestory(&pq);
}

int main()
{
	TestQueue();
	system("pause");
	return 0;
}