#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Move(char pos1, char pos2)
{
	printf("%c->%c ", pos1, pos2);
}
/*
n:�������Ӹ���
pos1����ʼλ��
pos2:  �м�λ��
pos3:  ����λ��
*/
void Hanota(int n, char pos1, char pos2, char pos3)
{
	//��ֹ����
	if (n == 1)
	{
		Move(pos1, pos3);
	}
	//�ݹ����
	else
	{
		Hanota(n-1, pos1, pos3, pos2);
		Move(pos1,pos3);
		Hanota(n - 1, pos2, pos1, pos3);
	}
}
int main()
{
	Hanota(1, 'A', 'B', 'C');
	printf("\n");
	Hanota(2, 'A', 'B', 'C');
	printf("\n");
	Hanota(3, 'A', 'B', 'C');
	printf("\n");
	return 0;
}