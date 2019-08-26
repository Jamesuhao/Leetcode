#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
int  twoSum(int* nums, int numsSize, int target,int *px,int *py)
{
	int i = 0;
	int j = 0;
	assert(nums != NULL);
	for (i = 0; i < numsSize-1; i++)
	{
		for (j = i+1; j < numsSize; j++)
		{
			if ((nums[i] + nums[j] )== target)
			{
				*px= i;
				*py= j;
			}
		}
	}
}
int main()
{
	int x = 0;
	int y = 0;
	int numSize = 0;
	int target = 0;
	int num[4] = { 2, 7, 11, 15 };
	numSize = sizeof(num) / sizeof(num[0]);
	scanf("%d", &target);
	twoSum(num, numSize, target,&x,&y);
	printf("%d %d\n",x, y);
	return 0;
}