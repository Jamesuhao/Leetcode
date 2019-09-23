#pragma once
#include<stdio.h>
//���һ��֧�� push��pop��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
//push(x) --��Ԫ�� x ����ջ�С�
//pop() --ɾ��ջ����Ԫ�ء�
//top() --��ȡջ��Ԫ�ء�
//getMin() --����ջ�е���СԪ�ء�
//ʾ�� :
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   -- > ���� - 3.
//minStack.pop();
//minStack.top();      -- > ���� 0.
//minStack.getMin();   -- > ���� - 2.

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
