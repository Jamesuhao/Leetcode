#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	int i = 0;
	int right = 0;
	int left = 0;
	int pos_column = 0;
	*returnSize = 0;
	int** result = (int**)malloc(sizeof(int*) * numsSize * numsSize);
	*returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);
	qsort(nums, numsSize, sizeof(int), compare);

	//≤È—Ø


	for (i = 0; i < numsSize - 2; i++)
	{
		if (i == 0 || (i > 0) && (nums[i] != nums[i - 1]))
		{
			left = (i + 1);
			right = (numsSize - 1);
			while (left < right)
			{
				if (nums[i] + nums[left] + nums[right] == 0)
				{
					result[*returnSize] = (int*)malloc(sizeof(int) * 3);
					result[*returnSize][0] = nums[i];
					result[*returnSize][1] = nums[left];
					result[*returnSize][2] = nums[right];
					(*returnColumnSizes)[pos_column] = 3;
					pos_column++;
					(*returnSize)++;
					while (left < right && nums[left] == nums[left + 1])
					{
						left++;
					}
					while (left < right && nums[right] == nums[right - 1])
					{
						right--;
					}
					left++;
					right--;
				}
				else if (nums[i] + nums[left] + nums[right] > 0)
				{
					right--;
				}
				else if (nums[i] + nums[left] + nums[right] < 0)
				{
					left++;
				}
			}
		}
	}
	return result;
}



int main()
{
	int nums[] = { -1,0,1,2,-1,-4 };
	int numsSize = sizeof(nums) / sizeof(int); int returnSize; int* returnColumnSizes = NULL;
	int** result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
	int i;
	for (i = 0; i < returnSize; i++) {
		printf("Main result[%d],nums=[%d,%d,%d]\n", i, result[i][0], result[i][1], result[i][2]);
		free(result[i]);
	}
	for (i = 0; i < returnSize; i++) {				//¥Ú”°
		printf("Main returnColumnSizes[%d]:%d\n", i, returnColumnSizes[i]);
	}
	free(result);
	free(returnColumnSizes);

	printf("returnSize = %d\n", returnSize);
	return 0;
}