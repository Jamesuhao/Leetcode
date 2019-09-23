#pragma once
#include<stdio.h>
//设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
//push(x) --将元素 x 推入栈中。
//pop() --删除栈顶的元素。
//top() --获取栈顶元素。
//getMin() --检索栈中的最小元素。
//示例 :
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   -- > 返回 - 3.
//minStack.pop();
//minStack.top();      -- > 返回 0.
//minStack.getMin();   -- > 返回 - 2.

typedef int DataType;
typedef struct Stack
{
	DataType* _a;
	size_t _top;
	size_t _capacity;
}Stack;
void StackInit(Stack* st);
void StackDestory(Stack* st);
void StackPush(Stack* st, DataType x);
void StackPop(Stack* st);
DataType StackTop(Stack* st);
size_t StackSize(Stack* st);
int StackEmpty(Stack* st);
