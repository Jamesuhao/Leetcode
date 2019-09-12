#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//题目：给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 - 1。
//示例 1:
//输入 : nums = [-1, 0, 3, 5, 9, 12], target = 9
//输出 : 4
//解释 : 9 出现在 nums 中并且下标为 4
//示例 2 :
//输入 : nums = [-1, 0, 3, 5, 9, 12], target = 2
//输出 : -1
//解释 : 2 不存在 nums 中因此返回 - 1
//提示：
//1.n 将在[1, 10000]之间。
//2.nums 的每个元素都将在[-9999, 9999]之间
int search(int* nums, int numsSize, int target)
{
	int mid = 0;
	int start = 0;
	int end = numsSize - 1;
	if (nums == NULL || numsSize == 0)
	{
		return -1;
	}
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid]>target)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return -1;
}
int main()
{
	int num[] = { -1, 0, 3, 5, 9, 12 };
	int len = sizeof(num) / sizeof(num[0]);
	int p = search(num, len, 13);
	printf("%d\n", p);
	return 0;
}