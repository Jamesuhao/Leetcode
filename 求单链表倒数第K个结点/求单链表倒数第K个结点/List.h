#ifndef __LIST_H__
#define __LIST_H__
//#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node, *pList;
//��ʼ��
void InitList(pList plsit);
//ͷ��
void InsertHead(pList plist, int val);
//β��
//void  InsertTail(pList plist, int val);
//��ӡ
void Show(pList plist);
//����
//������K�����
Node *LastkNode(pList plist, int k);


#endif //__LIST_H__