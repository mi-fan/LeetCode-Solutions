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
	int begin = 0, end = numsSize - 1;

	while(1)
	{
		mid = (begin + end)/2;
		if (nums[begin] > target || nums[end] < target)
			return arr;
		if (begin == end)
		{
			if (nums[begin] == target)
			{
				arr[0] = begin;
				arr[1] = end;
			}
			else
			{
				arr[0] = -1;
				arr[1] = -1;
			}
			return arr;
		}	
		else if (nums[mid] == target)
		{
			i = mid;
			j = mid;
			while(nums[i] == target && i >= 0) i--;
			while(nums[j] == target && j < numsSize) j++;
			arr[0] = i + 1;
			arr[1] = j - 1;
		}
		else if (nums[mid] < target)
		{
			begin = mid + 1;
		}
		else
		{
			end = mid;
		}
	}
}