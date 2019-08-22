#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Move(char pos1, char pos2)
{
	printf("%c->%c ", pos1, pos2);
}
/*
n:代表盘子个数
pos1：开始位置
pos2:  中间位置
pos3:  结束位置
*/
void Hanota(int n, char pos1, char pos2, char pos3)
{
	//终止条件
	if (n == 1)
	{
		Move(pos1, pos3);
	}
	//递归调用
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