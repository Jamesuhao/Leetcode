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
//��ӡ
void Show1(pList plist);
void Show2(pList plist);
//void ReverseList(pList head);
Node *ReverseList(pList head);


#endif //__LIST_H__