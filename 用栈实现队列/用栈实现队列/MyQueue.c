#include<malloc.h>
#include<assert.h>
#include"MyQueue.h"
#include<stdbool.h>
void StackInit(Stack* st)
{
	assert(st);
	st->_a = NULL;
	st->_capacity = 0;
	st->_top = 0;
}
void StackDestory(Stack* st)
{
	assert(st);
	free(st->_a);
	st->_capacity = st->_top = 0;
}
void StackPush(Stack* st, DataType x)
{
	assert(st);
	//入栈：顺序表的尾插
	//检查容量
	if (st->_capacity == st->_top)
	{
		size_t newcapacity = st->_capacity == 0 ? 10 : 2 * st->_capacity;
		st->_a = (DataType*)realloc(st->_a, newcapacity * sizeof(DataType));
		//st->_a = (DataType*)malloc(sizeof(Stack)* newcapacity);
		st->_capacity = newcapacity;
	}
	//插入
	st->_a[st->_top] = x;
	st->_top++;
}
void StackPop(Stack* st)
{
	assert(st);
	if (st->_top > 0)
	{
		--st->_top;
	}
}
DataType StackTop(Stack* st)
{
	assert(st);
	return st->_a[st->_top - 1];
}
size_t StackSize(Stack* st)
{
	assert(st);
	return st->_top;
}
int StackEmpty(Stack* st)
{
	assert(st);
	return st->_top == 0 ? 1 : 0;
}

typedef struct
{
	Stack q1;
	Stack q2;
}MyQueue;



MyQueue* myQueueCreate()
{
	MyQueue* Qu = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&Qu->q1);
	StackInit(&Qu->q2);
	return Qu;
}


void myQueuePush(MyQueue* obj, int x)
{
	assert(obj);
	StackPush(&obj->q1, x);
}
int myQueuePop(MyQueue* obj)
{
	assert(obj);
	if (StackEmpty(&obj->q2) == 1)
	{
		while (StackEmpty(&obj->q1) == 0)
		{
			StackPush(&obj->q2, StackTop(&obj->q1));
			StackPop(&obj->q1);
		}
	}
	DataType y = StackTop(&obj->q2);
	StackPop(&obj->q2);
	return y;
}
int myQueuePeek(MyQueue* obj) 
{
	assert(obj);
	if (StackEmpty(&obj->q2) == 1)
	{
		while (StackEmpty(&obj->q1) == 0)
		{
			StackPush(&obj->q2, StackTop(&obj->q1));
			StackPop(&obj->q1);
		}
	}
	return StackTop(&obj->q2);
}
bool myQueueEmpty(MyQueue* obj) {
	assert(obj);
	return StackEmpty(&obj->q1) && StackEmpty(&obj->q2) == 1 ? 1 : 0;
}

void myQueueFree(MyQueue* obj) {
	assert(obj);
	StackDestory(&obj->q1);
	StackDestory(&obj->q2);
	free(obj);
}
//["MyQueue", "push", "push", "peek", "pop", "empty"]
//[[], [1], [2], [], [], []]
int main()
{
	MyQueue *obj;
	obj = myQueueCreate();
	myQueuePush(obj, 1);
	myQueuePush(obj, 2);
	myQueuePush(obj, 3);
	myQueuePush(obj, 4);
	myQueuePush(obj, 5);
	myQueuePush(obj, 6);
	myQueuePeek(obj);
	myQueuePop(obj);
	myQueueEmpty(obj);
	return 0;
}