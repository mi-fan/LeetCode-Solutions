/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */



int** threeSum(int* nums, int numsSize, int* returnSize) {
	int i, j, k;
	int temp;
	int **returnArr;// =  (int**)calloc(4048,sizeof(int*));
	int max = numsSize * 6;
	int mid;

 
	returnArr = (int**)malloc(sizeof(int*)*max);

	for (i = 0; i < max; i++)
	{
		returnArr[i] = (int*)malloc(sizeof(int) * 3);
	}

	int comp(const void *a, const void *b);

	qsort(nums, numsSize, sizeof(int), comp);
	i = 0;
	*returnSize = 0;
	k = numsSize - 1;
	max = nums[numsSize - 1];

	while (nums[i] <= 0)
	{
		j = i + 1;
		while (j < k)
		{
			temp = nums[j] + nums[k] + nums[i];
			if (temp == 0)
			{
				returnArr[(*returnSize)][0] = nums[i];
				returnArr[(*returnSize)][1] = nums[j];
				returnArr[(*returnSize)][2] = nums[k];
				(*returnSize)++;
				do
				{
					k--;
				}while(nums[k] == nums[k + 1] && k > j);
			}else if (temp > 0)
			{
				k--;
			}
			else
			{
				j++;
			}
		}
		if (nums[i] == 0)
			break;
		do
		{
			i++;
		} while (nums[i] == nums[i - 1] && i < numsSize - 2);
	}

	return returnArr;
}

int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}