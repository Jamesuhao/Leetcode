#include"MinStack.h"
#include<malloc.h>
#include<assert.h>

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
	st->_capacity = 0;
	st->_top = 0;
}
void StackPush(Stack* st, DataType x)
{
	assert(st);
	if (st->_capacity == st->_top)
	{
		size_t newcapacity = st->_capacity == 0 ? 10 : 2 * st->_capacity;
		st->_a = (DataType*)realloc(st->_a,sizeof(DataType) * st->_capacity);
		st->_capacity = newcapacity;
	}
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
	return st->_a[st->_top-1];
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
} MinStack;
//initialize your data structure here. 
MinStack* minStackCreate()
{
	MinStack* st = (MinStack*)malloc(sizeof(MinStack));
	StackInit(&st->q1);
	StackInit(&st->q2);
	return st;
}
void minStackPush(MinStack* obj, int x)
{
	assert(obj);
	StackPush(&obj->q1, x);
	if (StackEmpty(&obj->q2) == 1 || x <= StackTop(&obj->q2))
	{
		StackPush(&obj->q2, x);
	}
}
void minStackPop(MinStack* obj)
{
	assert(obj);
	if (StackTop(&obj->q1) == StackTop(&obj->q2))
	{
		StackPop(&obj->q2);
	}
	StackPop(&obj->q1);
}
int minStackTop(MinStack* obj)
{
	assert(obj);
	return StackTop(&obj->q1);
}
int minStackGetMin(MinStack* obj)
{
	assert(obj);
	return StackTop(&obj->q2);
}
void minStackFree(MinStack* obj)
{
	assert(obj);
	StackDestory(&obj->q1);
	StackDestory(&obj->q2);
	free(obj);
}