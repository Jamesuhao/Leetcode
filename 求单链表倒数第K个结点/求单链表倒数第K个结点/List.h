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
//初始化
void InitList(pList plsit);
//头插
void InsertHead(pList plist, int val);
//尾插
//void  InsertTail(pList plist, int val);
//打印
void Show(pList plist);
//查找
//倒数第K个结点
Node *LastkNode(pList plist, int k);


#endif //__LIST_H__