#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//二维数组解法：
//#define rows 4
//#define cols 4
//
//int Find_numbers(int arr[rows][cols],  int key)
//{
//	if (arr == NULL || rows < 0 || cols < 0)
//	{
//		printf("error\n");
//	}
//	int row = 0;
//	int col = cols - 1;
//	//int val = arr[row][col];
//	while ((row < rows) && (col >= 0))
//	{
//		if (arr[row][col]== key)
//		{
//			return key;
//		}
//		else if (arr[row][col]>key)
//		{
//			col--;
//		}
//		else
//		{
//			row++;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int k = 0;
//	int key = 0;
//	int arr[4][4] = { { 1, 2, 8, 9 }, 
//	                       { 2, 4, 9, 12 }, 
//						   { 4, 7, 10, 13 }, 
//						   { 6, 8, 11, 15 } };
//	printf("请输入需要判断的数：");
//	scanf("%d", &k);
//	key =Find_numbers(arr,k);
//	printf("%d\n", key);
//	return 0;
//}

//一维数组解法
int  Find_numbers(int *arr, int row, int col, int key,int *px,int *py)
{
	int tmpRow = 0;
	int tmpCol = col - 1;
	while ((row > tmpRow) && (tmpCol >= 0))
	{
		if (arr[tmpRow*col+tmpCol]== key)
		{
			*px = tmpRow;
			*py = tmpCol;
			return key;
		}
		else if (arr[tmpRow*col + tmpCol] >key)
		{
			tmpCol--;
		}
		else
		{
			tmpRow++;
		}
	}
	return -1;
}
int main()
{
	int k = 0;
	int key = 0;
	int x = -1;
	int y = -1;
	int arr[4][4] = { { 1, 2, 8, 9 }, 
	                       { 2, 4, 9, 12 }, 
						   { 4, 7, 10, 13 }, 
						   { 6, 8, 11, 15 } };
	printf("请输入需要判断的数：");
	scanf("%d", &k);
	key = Find_numbers((int *)arr, 4, 4, k, &x, &y);
	printf("%d,%d,%d\n", key,x,y);
	return 0;
}

