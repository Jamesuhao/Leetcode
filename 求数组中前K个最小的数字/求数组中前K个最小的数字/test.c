#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Partion(int arr[], int left, int right)
{
	int tmp = arr[left];
	while (left < right)
	{
		//�ұ��ұ�tmpС������
		while ((left < right) && (arr[right] >= tmp))
		{
			right--;
		}
		if (left >= right)
		{
			//arr[left] = tmp;
			break;
		}
		else
		{
			arr[left] = arr[right];
		}
		while ((left < right) && (arr[left] <= tmp))
		{
			left++;
		}
		if (left >= right)
		{
			//arr[left] = tmp;
			break;
		}
		else
		{
			arr[right] = arr[left];
		}
	}
	arr[left] = tmp;
	return left;
}
void PreKNum(int *arr, int len, int k)
{
	int i = 0;
	int left = 0;
	int right = len - 1;
	int par = Partion(arr, left, right);
	while (par != k - 1)
	{
		if (par > k - 1)
		{
			right = par - 1;
			par = Partion(arr, left, right);
		}
		else
		{
			left = par + 1;
			par = Partion(arr, left, right);
		}
	}
	for (i = 0; i < k; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int len = 0;
	int arr[] = { 12,3,5,17,0,7,14,8,4 };
	len = sizeof(arr) / sizeof(arr[0]);
	PreKNum(arr, len, 5);
	return 0;
}