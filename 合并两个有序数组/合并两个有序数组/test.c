#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
//说明 :
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素
//提示：如果从末尾填充较长的数组而不是从开始填充该怎么办？
//示例：
//输入:
//nums1 = [1, 2, 3, 0, 0, 0], m = 3
//nums2 = [2, 5, 6], n = 3
//输出 : [1, 2, 2, 3, 5, 6]
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	if (nums1 == NULL || nums1Size == 0 || nums2 == NULL || nums2Size == 0)
	{
		return;
	}
	if (n == 1 && m == 0)
	{
		nums1[0] = nums2[0];
		return;
	}
	while (n)
	{

		if ((m == 0) || (nums2[n - 1] >= nums1[m - 1]))
		{
			nums1[m + n - 1] = nums2[n - 1];
			n--;
		}
		else
		{
			nums1[m + n - 1] = nums1[m - 1];
			m--;
		}
	}
}
int main()
{
	int nums1[6] = { 4,5,6 };
	int nums2[3] = { 1,2,3 };
	int i = 0;
	int len1 = sizeof(nums1) / sizeof(nums1[0]);
	int len2 = sizeof(nums2) / sizeof(nums2[0]);
	merge(nums1, len1, 3, nums2, len2, 3);
	for (i = 0; i < len1; i++)
	{
		printf("%d ", nums1[i]);
	}
	printf("\n");
	return 0;
}