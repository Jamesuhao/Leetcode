#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Count_one(unsigned int x)
{
	int n = 0;
	while (x)
	{
		n++;
		x = x&(x - 1);
	}
	return n;
}

int main()
{
	unsigned int x = 0;
	int k = 0;
	printf("������ͳ�Ƶ�����:\n");
	scanf("%d", &x);
	k = Count_one(x);
	printf("%d���ڴ��ж�����1�ĸ���Ϊ%d\n",x,k);
	return 0;
}