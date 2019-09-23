#include"MyStack.h"
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>
void QueueInit(Queue* p)
{
	assert(p);
	p->_front = p->_rear = NULL;
}
void QueueDestory(Queue* p)
{
	assert(p);
	QueueNode* cur = p->_front;
	while (cur)
	{
		p->_front = cur->_next;
		free(cur);
		cur = p->_front;
	}
	p->_rear = NULL;
}
//入队：单链表的尾插
void QueuePush(Queue* p, DataType x)
{
	assert(p);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->_data = x;
	newNode->_next = NULL;
	if (p->_front == NULL)
	{
		p->_front = newNode;
		p->_rear = newNode;
	}
	else
	{
		p->_rear->_next = newNode;
		p->_rear = p->_rear->_next;
	}
}
//出队：单链表的头删
void QueuePop(Queue* p)
{
	assert(p);
	if (p->_front)
	{
		QueueNode* next = p->_front->_next;
		free(p->_front);
		p->_front = next;
		if (p->_front == NULL)
		{
			p->_rear = NULL;
		}
	}
}
//获取队首元素
DataType QueueFront(Queue* p)
{
	assert(p);
	return p->_front->_data;
}
//获取队尾元素
DataType QueueBack(Queue* p)
{
	assert(p);
	return p->_rear->_data;
}
//判断队列是否为空
int QueueEmpty(Queue* p)
{
	assert(p);
	if (p->_front == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//队列大小
int QueueSize(Queue* p)
{
	assert(p);
	QueueNode* cur = p->_front;
	DataType n = 0;
	while (cur)
	{
		cur = cur->_next;
		++n;
	}
	return n;
}
typedef struct
{
	Queue q1;
	Queue q2;
} MyStack;
MyStack* myStackCreate()
{
	MyStack* st = (QueueNode*)malloc(sizeof(MyStack));
	QueueInit(&st->q1);
	QueueInit(&st->q2);
	return st;
}
void myStackPush(MyStack* obj, int x)
{
	assert(obj);
	if (QueueEmpty(&obj->q1) == 1)
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}
int myStackPop(MyStack* obj)
{
	Queue* emptyQ = NULL;
	Queue* fullQ = NULL;
	if (QueueEmpty(&obj->q1) == 1)
	{
		emptyQ = &obj->q1;
		fullQ = &obj->q2;
	}
	else
	{
		emptyQ = &obj->q2;
		fullQ = &obj->q1;
	}
	while (QueueSize(fullQ) > 1)
	{
		QueuePush(emptyQ, QueueBack(fullQ));
		QueuePop(fullQ);
	}
	DataType front = QueueFront(fullQ);
	QueuePop(fullQ);
	return front;
}
int myStackTop(MyStack* obj)
{
	assert(obj);
	Queue* emptyQ = NULL;
	Queue* fullQ = NULL;
	if (QueueEmpty(&obj->q1) == 1)
	{
		emptyQ = &obj->q1;
		fullQ = &obj->q2;
	}
	else
	{
		emptyQ = &obj->q2;
		fullQ = &obj->q1;
	}
	while (QueueSize(fullQ) > 1)
	{
		QueuePush(emptyQ, QueueBack(fullQ));
		QueuePop(fullQ);
	}
	DataType top = QueueFront(fullQ);
	QueuePush(emptyQ, top);
	QueuePop(fullQ);
	return top;
}
bool myStackEmpty(MyStack* obj)
{
	assert(obj);
	return (QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2));
}
void myStackFree(MyStack* obj)
{
	assert(obj);
	QueueDestory(&obj->q1);
	QueueDestory(&obj->q2);
	free(obj);
}