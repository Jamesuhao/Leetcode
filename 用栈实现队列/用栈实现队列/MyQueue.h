#pragma once
#include<stdio.h>
//ʹ��ջʵ�ֶ��е����в�����
//push(x) --��һ��Ԫ�ط�����е�β����
//pop() --�Ӷ����ײ��Ƴ�Ԫ�ء�
//peek() --���ض����ײ���Ԫ�ء�
//empty() --���ض����Ƿ�Ϊ�ա�
//ʾ�� :
//MyQueue queue = new MyQueue();
//queue.push(1);
//queue.push(2);
//queue.peek();  // ���� 1
//queue.pop();   // ���� 1
//queue.empty(); // ���� false
//˵��:
//��ֻ��ʹ�ñ�׼��ջ���� -- Ҳ����ֻ�� push to top, peek / pop from top, size, �� is empty �����ǺϷ��ġ�
//����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
//�������в���������Ч�� �����磬һ���յĶ��в������ pop ���� peek ��������
typedef int DataType;
typedef struct	Stack
{
	DataType* _a;
	size_t _capacity;
	size_t _top;
}Stack;
void StackInit(Stack* st);
void StackDestory(Stack* st);
void StackPush(Stack* st, DataType x);
void StackPop(Stack* st);
DataType StackTop(Stack* st);
size_t StackSize(Stack* st);
int StackEmpty(Stack* st);

