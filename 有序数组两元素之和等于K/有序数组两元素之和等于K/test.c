//#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//
//typedef struct Subscript
//{
//	int x;
//	int y;
//}A;
//A array;
//void FindSubscript(int *arr,int n,int k)
//{
//	int left = 0;
//	int right = n - 1;
//	int sum = 0;
//	while (left <= right)
//	{
//		sum = arr[left] + arr[right];
//		if (sum < k)
//		{
//			left++;
//		}
//		else if (sum > k)
//		{
//			right--;
//		}
//		else
//		{
//			array.x= left;
//			array.y = right;
//			break;
//		}
//	}
//}
//int main()
//{
//	int k = 0;
//	int n = 0;
//	int arr[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, };
//	n = sizeof(arr) / sizeof(arr[0]);
//	printf("请输入需要查找的数：\n");
//	scanf("%d", &k);
//	FindSubscript(arr, n, k);
//	printf("之和为%d的两个元素下标为%d %d\n", k, array.x, array.y);
//	return 0;
//}
char * addBinary(char * a, char * b)
{
	int len1 = strlen(a);
	int len2 = strlen(b);
	char carry = '0';
	char pa ;
	char pb;
	int len = len1 > len2 ? len1 : len2;

	if (a == NULL || b == NULL)
	{
		return NULL;
	}
	char *res = (char *)malloc(sizeof(char)*(len + 2));
	res[++len] = 0;
	while (len > 1 || carry == '1')
	{
		pa = len1 > 0 ? a[--len1] : '0';
		pb = len2 > 0 ? b[--len2] : '0';
		res[--len] = pa^pb^carry;
		carry = (pa&carry) | (pb&carry) | (pa&pb);
	}
	return res + len;
	
}
int main()
{
	char a[] = "1";
	char b[] = "111";
	char *p = addBinary(a, b);
	printf("%s\n", p);
	return 0;
}