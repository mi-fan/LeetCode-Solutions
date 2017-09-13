/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
*/

int threeSumClosest(int* nums, int numsSize, int target) {
    int i, j ,k;
    int temp, diff;
    int min, sum;

    int comp(const void *a, const void *b);
    void checkDiff(int diff, int temp, int *min, int*sum);

	qsort(nums, numsSize, sizeof(int), comp);

	min = target;
	sum = 0;
	i = 0;

	while (i < numsSize - 2)
	{
		j = i + 1;
		k = numsSize - 1;

		while (j < k)
		{
			temp = nums[i] + nums[j] + nums[k];
			diff = temp - target;

			if (diff == 0)
				return temp;
			else if (diff < 0)
			{
				checkDiff(diff, temp, &min, &sum);
				j++;
			}
			else
			{
				checkDiff(diff, temp, &min, &sum);
				k--;
			}
		}

		do
		{
			i++;
		}while(nums[i] == nums[i - 1] && i < numsSize - 2);
	}
	return sum;
}

int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void checkDiff(int diff, int temp,int *min, int *sum)
{
	int ref = (diff > 0)? diff : (-diff);

	if (ref < *min)
	{
		*min = ref;
		*sum = temp;
	}

	return;
}