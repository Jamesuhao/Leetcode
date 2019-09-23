#include<stdio.h>
//ʹ�ö���ʵ��ջ�����в�����
//push(x) --Ԫ�� x ��ջ
//pop() --�Ƴ�ջ��Ԫ��
//top() --��ȡջ��Ԫ��
//empty() --����ջ�Ƿ�Ϊ��
//ע�� :
//��ֻ��ʹ�ö��еĻ�������-- Ҳ���� push to back, peek / pop from front, size, �� is empty ��Щ�����ǺϷ��ġ�
//����ʹ�õ�����Ҳ��֧�ֶ��С� �����ʹ�� list ���� deque��˫�˶��У���ģ��һ������, ֻҪ�Ǳ�׼�Ķ��в������ɡ�
//����Լ������в���������Ч�ģ�����, ��һ���յ�ջ������� pop ���� top ��������
//ʾ����
//["MyStack", "push", "push", "top", "pop", "empty"]
//[[], [1], [2], [], [], []]
typedef int DataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	DataType _data;
}QueueNode;
typedef struct Queue
{
	QueueNode* _front;//��ͷ
	QueueNode* _rear;//��β
}Queue;
void QueueInit(Queue* p);
void QueueDestory(Queue* p);
void QueuePush(Queue* p, DataType x);
void QueuePop(Queue* p);
DataType QueueFront(Queue* p);
DataType QueueBack(Queue* p);
int QueueEmpty(Queue* p);
int QueueSize(Queue* p);