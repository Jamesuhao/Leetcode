#include<stdio.h>
#include<malloc.h>
#include<assert.h>
//设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针 / 引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0 - index 的。
//在链表类中实现这些功能：
//get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回 - 1。
//addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
//addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
//addAtIndex(index, val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
//deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
//示例：
//MyLinkedList linkedList = new MyLinkedList();
//linkedList.addAtHead(1);
//linkedList.addAtTail(3);
//linkedList.addAtIndex(1, 2);   //链表变为1-> 2-> 3
//linkedList.get(1);            //返回2
//linkedList.deleteAtIndex(1);  //现在链表是1-> 3
//linkedList.get(1);            //返回3
//提示：
//所有val值都在[1, 1000] 之内。
//操作次数将在[1, 1000] 之内。
//请不要使用内置的 LinkedList 库
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