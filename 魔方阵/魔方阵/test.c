#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define ROW 3
void Func2(int arr[][ROW])
{
	int tmpRow = 0;
	int tmpCol = ROW / 2;
	int i = 2;
	arr[tmpRow][tmpCol] = 1;
	//2-n^2
	for (i = 2; i <= ROW*ROW; i++)
	{
		if (arr[(tmpRow-1+ROW)%ROW][(tmpCol+1)%ROW] != 0)
		{
			tmpRow = (tmpRow + 1) % ROW;
		}
		else
		{
			tmpRow = (tmpRow - 1 + ROW) % ROW;
			tmpCol = (tmpCol + 1) % ROW;
		}
		arr[tmpRow][tmpCol] = i;
	}
}
void Show(int arr[][ROW])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < ROW; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][3] = { 0 };
	Func2(arr);
	Show(arr);
	return 0;
}