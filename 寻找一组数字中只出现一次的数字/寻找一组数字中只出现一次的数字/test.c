#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//运用异或的特点，相异为1，相同为0
void Find_number(int *arr, int *px, int *py, int len)
{
	int i = 0;
	int sum = 0;
	int pos = 0;
	for (i = 0; i < len; i++)
	{
		sum = sum^arr[i];
	}
	for (i = 0; i < 32; i++)
	{
		if (((sum >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	for (i = 0; i < len; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			*px = *px^arr[i];
		}
		else
		{
			*py = *py^arr[i];
		}
	}
}

int main()
{
	int x = 0;
	int y = 0;
	int len = 0;
	int arr[] = { 1, 3, 5, 7, 1, 3, 5, 9 };
	len = sizeof(arr) / sizeof(arr[0]);
	Find_number(arr, &x, &y, len);
	printf("%d %d\n", x, y);
	return 0;
}