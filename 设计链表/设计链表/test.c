#include<stdio.h>
#include<malloc.h>
#include<assert.h>
//��������ʵ�֡�������ѡ��ʹ�õ������˫�����������еĽڵ�Ӧ�þ����������ԣ�val �� next��val �ǵ�ǰ�ڵ��ֵ��next ��ָ����һ���ڵ��ָ�� / ���á����Ҫʹ��˫����������Ҫһ������ prev ��ָʾ�����е���һ���ڵ㡣���������е����нڵ㶼�� 0 - index �ġ�
//����������ʵ����Щ���ܣ�
//get(index)����ȡ�����е� index ���ڵ��ֵ�����������Ч���򷵻� - 1��
//addAtHead(val)��������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ val �Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ㡣
//addAtTail(val)����ֵΪ val �Ľڵ�׷�ӵ���������һ��Ԫ�ء�
//addAtIndex(index, val)���������еĵ� index ���ڵ�֮ǰ���ֵΪ val  �Ľڵ㡣��� index ��������ĳ��ȣ���ýڵ㽫���ӵ������ĩβ����� index ���������ȣ��򲻻����ڵ㡣���indexС��0������ͷ������ڵ㡣
//deleteAtIndex(index)��������� index ��Ч����ɾ�������еĵ� index ���ڵ㡣
//ʾ����
//MyLinkedList linkedList = new MyLinkedList();
//linkedList.addAtHead(1);
//linkedList.addAtTail(3);
//linkedList.addAtIndex(1, 2);   //�����Ϊ1-> 2-> 3
//linkedList.get(1);            //����2
//linkedList.deleteAtIndex(1);  //����������1-> 3
//linkedList.get(1);            //����3
//��ʾ��
//����valֵ����[1, 1000] ֮�ڡ�
//������������[1, 1000] ֮�ڡ�
//�벻Ҫʹ�����õ� LinkedList ��
typedef struct Node
{
	int val;
	struct Node* next;
}Node;
typedef struct MyLinkedList
{
	struct Node* head;
}MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate()
{
	MyLinkedList* List = (MyLinkedList*)calloc(1, sizeof(MyLinkedList));
	return List;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index)
{
	assert(obj);
	if (index < 0)
	{
		return -1;
	}
	int i = 0;
	Node* cur = obj->head;
	while (cur)
	{
		if (i == index)
		{
			return cur->val;
		}
		i++;
		cur = cur->next;
	}
	return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
	assert(obj);
	Node* newNode = (Node*)calloc(1, sizeof(Node));
	newNode->val = val;
	newNode->next = obj->head;
	obj->head = newNode;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
	assert(obj);
	Node* newNode = (Node*)calloc(1, sizeof(Node));
	newNode->val = val;
	newNode->next = NULL;
	Node* cur = obj->head;
	while (cur)
	{
		if (cur->next == NULL)
		{
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)
{
	assert(obj);
	if (index <= 0)
	{
		myLinkedListAddAtHead(obj, val);
		return;
	}
	Node* newNode = (Node*)calloc(1, sizeof(Node));
	newNode->val = val;
	newNode->next = NULL;
	Node* cur = obj->head;
	int i = 1;
	while (cur)
	{
		if (i == index)
		{
			Node* pnext = cur->next;
			cur->next = newNode;
			newNode->next = pnext;
			return;
		}
		i++;
		cur = cur->next;
	}
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index)
{
	assert(obj);
	if (index < 0)
	{
		return;
	}
	if (index == 0)
	{
		Node* cur = obj->head;
		Node* pnext = cur->next;
		obj->head = pnext;
		free(cur);
		cur = NULL;
		return;
	}
	else
	{
		Node* cur = obj->head;
		int i = 1;
		while (cur)
		{
			if (i == index && cur->next)
			{
				Node* pnext = cur->next;
				cur->next = pnext->next;
				free(pnext);
				pnext = NULL;
				return;
			}
			i++;
			cur = cur->next;
		}
	}
}

void myLinkedListFree(MyLinkedList* obj)
{
	assert(obj);
	Node* cur = obj->head;
	while (cur)
	{
		Node* tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = NULL;
	}

}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/