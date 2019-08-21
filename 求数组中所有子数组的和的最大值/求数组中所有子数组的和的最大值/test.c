#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//题目：
//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//示例 :
//输入 : [-2, 1, -3, 4, -1, 2, 1, -5, 4],
//输出 : 6
//解释 : 连续子数组 [4, -1, 2, 1] 的和最大，为 6。

int Max_array(int *arr, int len)
{
	int i = 0;
	int sum = 0;	
	int maxsum = arr[0];
//O(n)
	for (i = 0; i < len; i++)
	{
		if (sum<0)
		{
			sum = arr[i];
		}
		else
		{
			sum += arr[i];
		}
		if (sum>maxsum)
		{
			maxsum = sum;
		}
	}
//动态规划
	for (i = 0; i < len; i++)
	{
		sum = sum + arr[i];
		if (sum<arr[i])
		{
			sum = arr[i];
		}
		if (sum>maxsum)
		{
			maxsum=sum;
		}
	}
	return maxsum;
}
int main()
{
	int max = 0;
	int len = 0;
	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	len = sizeof(arr) / sizeof(arr[0]);
	max = Max_array(arr, len);
	printf("%d\n", max);
	return 0;
}