#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>
//������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������
//ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��
//���ʵ��Ӧ��֧�����²�����
//MyCircularQueue(k) : �����������ö��г���Ϊ k ��
//Front : �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
//Rear : ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
//enQueue(value) : ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
//deQueue() : ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
//isEmpty() : ���ѭ�������Ƿ�Ϊ�ա�
//isFull() : ���ѭ�������Ƿ�������
//ʾ����
//MyCircularQueue circularQueue = new MycircularQueue(3); // ���ó���Ϊ 3
//circularQueue.enQueue(1);  // ���� true
//circularQueue.enQueue(2);  // ���� true
//circularQueue.enQueue(3);  // ���� true
//circularQueue.enQueue(4);  // ���� false����������
//circularQueue.Rear();  // ���� 3
//circularQueue.isFull();  // ���� true
//circularQueue.deQueue();  // ���� true
//circularQueue.enQueue(4);  // ���� true
//circularQueue.Rear();  // ���� 4
//��ʾ��
//���е�ֵ���� 0 �� 1000 �ķ�Χ�ڣ�
//���������� 1 �� 1000 �ķ�Χ�ڣ�
//�벻Ҫʹ�����õĶ��п⡣
typedef struct 
{
	int* _a;
	int _front;
	int _rear;
	int _k;
} MyCircularQueue;
/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) 
{
	return obj->_front == obj->_rear;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return ((obj->_rear + 1) % (obj->_k) == (obj->_front));
}

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) 
{
	MyCircularQueue* Queue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	Queue->_a = (int*)malooc(sizeof(int)*(k + 1));
	Queue->_front = 0;
	Queue->_rear = 0;
	Queue->_k = k;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) 
{
	assert(obj);
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	obj->_a[obj->_rear] = value;
	obj->_rear++;
	if (obj->_rear == obj->_k + 1)
	{
		obj->_rear = 0;
	}
	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) 
{
	assert(obj);
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	obj->_front++;
	if (obj->_front == obj->_k + 1)
	{
		obj->_front = 0;
	}
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) 
{
	assert(obj);
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->_a[obj->_front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) 
{
	assert(obj);
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	if (obj->_rear == 0)
	{
		return obj->_a[obj->_k];
	}
	return obj->_a[obj->_rear - 1];
}
void myCircularQueueFree(MyCircularQueue* obj) 
{
	free(obj->_a);
	free(obj);
}