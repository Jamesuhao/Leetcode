#include<stdio.h>
#include<malloc.h>
//����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
//Ҫ�󷵻��������������
//ʾ����
//���룺
//{ "$id":"1","next" : 
//{"$id":"2","next" : null,"random" : 
//{"$ref":"2"},"val" : 2},"random" : 
//{"$ref":"2"},"val" : 1 }
//���ͣ�
//�ڵ� 1 ��ֵ�� 1��������һ��ָ������ָ�붼ָ��ڵ� 2 ��
//�ڵ� 2 ��ֵ�� 2��������һ��ָ��ָ�� null�����ָ��ָ�����Լ���
//��ʾ��
//����뷵�ظ���ͷ�Ŀ�����Ϊ�Կ�¡�б�����á�
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
		//����
		while (cur)
		{
			Node* next = cur->next;
			Node* copy = (Node*)malloc(sizeof(Node));
			copy->val = cur->val;
			cur->next = copy;
			copy->next = next;
			cur = next;
		}
		//����random
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
		//����
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
