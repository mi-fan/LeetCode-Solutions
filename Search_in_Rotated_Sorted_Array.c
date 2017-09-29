Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

int search(int* nums, int numsSize, int target) {
	if (numsSize == 0)
		return -1;
    return search_rot(nums, 0, numsSize - 1, target);
}

int search_rot(int* nums, int begin, int end, int target)
{
	if (begin == end)
	{
		if (nums[begin] == target) return begin;
		return -1;
	}
	int pos;
	int mid = (begin + end)/2;
	if (nums[mid] == target)
		return mid;

    if (nums[mid] > nums[begin])//the former part is fully ascending
	{
		if (nums[mid] >= target && nums[begin] <= target)
			pos = search_rot(nums, begin, mid, target);
		else
			pos = search_rot(nums, mid + 1, end, target);
	}
	else //the latter part is fully ascending
	{
		if (nums[mid] <= target && nums[end] >= target)
			pos = search_rot(nums, mid + 1, end, target);
		else
			pos = search_rot(nums, begin, mid, target);
	}


	return pos;
}
