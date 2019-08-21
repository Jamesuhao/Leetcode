#define _CRT_SECURE_NO_WARNINGS 1
//题目：
//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//给定 nums = [0, 0, 1, 1, 1, 1, 2, 3, 3],
//函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。
//你不需要考虑数组中超出新长度后面的元素。
#include<stdio.h>
int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize <= 1)
	{
		return numsSize;
	}
	int i = 0;
	int count = 1;
	for (i = 2; i<numsSize; i++)
	{
		if (nums[i] != nums[count - 1])
		{
			count++;
			nums[count] = nums[i];
		}
	}
	return count + 1;
}