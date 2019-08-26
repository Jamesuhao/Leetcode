#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int Partion(int *arr, int left, int right)
//{
//	int tmp = arr[left];
//	while (left < right)
//	{
//		while ((left < right) && (arr[right]>=tmp))
//		{
//			right--;
//		}
//		if (left >= right)
//		{
//			break;
//		}
//		else
//		{
//			arr[left] = arr[right];
//		}
//		while ((left < right) && (arr[left]<=tmp))
//		{
//			left++;
//		}
//		if (left >= right)
//		{
//			break;
//		}
//		else
//		{
//			arr[right] = arr[left];
//		}
//	}
//	arr[left] = tmp;
//	return left;
//}
//int ChenKmore(int *arr, int len, int result)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < len; i++)
//	{
//		if (arr[i] == result)
//		{
//			count++;
//		}
//	}
//	if (count >= result)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int Find_numbers(int *arr, int len)
//{
//	int mid = len / 2;
//	int left = 0;
//	int right = len - 1;
//	int result = 0;
//	int par = Partion(arr, left, right);
//	while (par != mid)
//	{
//		if (par > mid)
//		{
//			right = right - 1;
//			par = Partion(arr, left, right);
//		}
//		if (par < mid)
//		{
//			left = left +1;
//			par = Partion(arr, left, right);
//		}
//	}
//	result = arr[mid];
//	if (!ChenKmore(arr, len, result))
//	{
//		return -1;
//	}
//	return result;
//}
//int main()
//{
//	int len = 0;
//	int val = 0;
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//	len = sizeof(arr) / sizeof(arr[0]) ;
//	val = Find_numbers(arr, len);
//	if (val == -1)
//	{
//		printf("不存在超过数组长度一半的数字。\n");
//	}
//	else
//	{
//		printf("超过数组长度一半的数字为%d。\n", val);
//	}
//	return 0;
//}
int main()
{
	unsigned char a = 0xA5;
	unsigned char b = ~a >> 4 + 1;
	printf("%d\n", b);
}