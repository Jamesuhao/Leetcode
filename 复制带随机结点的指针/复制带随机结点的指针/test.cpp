#include<stdio.h>
#include<malloc.h>
//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//要求返回这个链表的深拷贝。
//示例：
//输入：
//{ "$id":"1","next" : 
//{"$id":"2","next" : null,"random" : 
//{"$ref":"2"},"val" : 2},"random" : 
//{"$ref":"2"},"val" : 1 }
//解释：
//节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
//节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
//提示：
//你必须返回给定头的拷贝作为对克隆列表的引用。
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};
class Solution {
public:
	Node* copyRandomList(Node* head)
	{
		Node* cur, * newhead, * newtail;
		if (head == NULL)
		{
			return head;
		}
		cur = head;
		//插入
		while (cur)
		{
			Node* next = cur->next;
			Node* copy = (Node*)malloc(sizeof(Node));
			copy->val = cur->val;
			cur->next = copy;
			copy->next = next;
			cur = next;
		}
		//更新random
		cur = head;
		while (cur)
		{
			Node* copy = cur->next;
			if (cur->random)
			{
				copy->random = cur->random->next;
			}
			else
			{
				copy->random = NULL;
			}
			cur = copy->next;
		}
		//断链
		cur = head;
		newhead = newtail = NULL;
		while (cur)
		{
			Node* copy = cur->next;
			if (newhead == NULL)
			{
				newhead = newtail = copy;
			}
			else
			{
				newtail->next = copy;
				newtail = copy;
			}
			cur->next = copy->next;
			cur = cur->next;
		}
	}
};
