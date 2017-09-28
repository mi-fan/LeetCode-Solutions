Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

void swap_two(int *p, int *q);
void n_sort(int *arr, int begin, int end);
int rearrange(int *arr, int begin, int end);

void swap_two(int *p, int *q);
void n_sort(int *arr, int begin, int end);
int rearrange(int *arr, int begin, int end);
void nextPermutation(int* nums, int numsSize) {
    int i, p, q, min;

    if (numsSize <= 1)
    	return;
    p = 0;
    for (i = 1; i < numsSize; i++)
    {
    	if (nums[i - 1] < nums[i])
    		p = i;
    } //p is the last position of ascending numbers

    if (p == 0)
    	n_sort(nums, 0, numsSize-1);
   	else
   	{
   		min = nums[p];
   		q = p;
   		for (i = p; i < numsSize; i++)
		{
			if (nums[i] > nums[p-1] && nums[i] < min)
			{
				q = i;
				min = nums[i];
			}

		}
   		swap_two(&nums[p-1], &nums[q]);
   	
   		n_sort(nums, p, numsSize-1);
   	}
   	return;
}

void swap_two(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
	return;
}

int rearrange(int *arr, int begin, int end)
{
	if (begin == end || begin + 1 == end)
	{
		return begin;
	}
	int p = begin, q = p + 1;
	int key = arr[begin];

	while(q <= end)
	{
		if (arr[q] < key)
			swap_two(&arr[++p], &arr[q]);
		q++;
	}
	swap_two(&arr[begin], &arr[p]);

	return p;
}

void n_sort(int *arr, int begin, int end)
{
	if (begin == end)
		return;
	if (begin + 1 == end)
	{
		if (arr[begin] > arr[end])
			swap_two(&arr[begin], &arr[end]);
		return;
	}

	int p = rearrange(arr, begin, end);

	if (p > begin)
		n_sort(arr, begin, p);
	if (p + 1 < end)
		n_sort(arr, p+1, end);

	return;
}