Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithms runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int i, j = 0;
	int *arr = (int *)malloc(2*sizeof(int));
	arr[0] = -1;
	arr[1] = -1;
	*returnSize = 2;
    if (!numsSize)
		return arr;

	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] == target)
		{
			if (j == 0)
			{
				arr[0] = i;
                arr[1] = i;
				j++;
			}
			else arr[1] = i;
			*returnSize = 2;
		}
        else if (nums[i] > target)
            break;
	}
	return arr;
}