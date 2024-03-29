#include<stdio.h>
//使用队列实现栈的下列操作：
//push(x) --元素 x 入栈
//pop() --移除栈顶元素
//top() --获取栈顶元素
//empty() --返回栈是否为空
//注意 :
//你只能使用队列的基本操作-- 也就是 push to back, peek / pop from front, size, 和 is empty 这些操作是合法的。
//你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列, 只要是标准的队列操作即可。
//你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
//示例：
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
	QueueNode* _front;//队头
	QueueNode* _rear;//队尾
}Queue;
void QueueInit(Queue* p);
void QueueDestory(Queue* p);
void QueuePush(Queue* p, DataType x);
void QueuePop(Queue* p);
DataType QueueFront(Queue* p);
DataType QueueBack(Queue* p);
int QueueEmpty(Queue* p);
int QueueSize(Queue* p);