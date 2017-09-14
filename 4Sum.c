//Given an array S of n integers, are there elements a, b, c, and d in S such that
// a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int **quad;
    int rows;
    int start, end, i, j;
    int old_s, old_e, new_s, new_e;
    int diff, temp;
    int flag = 0;

    int cmp(void *a, void *b);
    qsort(nums, numsSize, sizeof(int), cmp);

    *returnSize = 0;
    rows = numsSize*8;
    quad = (int**)malloc(sizeof(char*)*rows);
    for(i = 0; i < rows; i++)
    {
    	quad[i] = (int*)malloc(sizeof(char)*4);
    }
    
    for (start = 0; start < numsSize - 3; start++)
    {
    	if ((start != 0) && (nums[start] == nums[start - 1]))
    		continue;
	 if (nums[start] + nums[start + 1] + nums[start + 2] + nums[start + 3] > target)
            break;
        
    	for (end = numsSize - 1; end > start + 2; end--)
    	{
    		if ((end != numsSize - 1) && nums[end] == nums[end + 1])
    			continue;
 		
		if (nums[start] + nums[end] + nums[end - 1] + nums[end - 2] < target)
                	break;
		
		diff = target - (nums[start] + nums[end]);
	    	for (i = start + 1, j = end - 1; i < j; )
	    	{
			if (nums[start] + nums[end] + nums[i] + nums[i + 1] > target)
               		     break;
			if (nums[start] + nums[end] + nums[j] + nums[j - 1] < target)
			    break;
			
	    		temp = nums[i] + nums[j];
	    		if (temp == diff)
	    		{
	    			quad[*returnSize][0] = nums[start];
	    			quad[*returnSize][1] = nums[i];
	    			quad[*returnSize][2] = nums[j];
	    			quad[*returnSize][3] = nums[end];
	    			(*returnSize)++;
	    			upd_idx(nums, &i, 1);
	    			upd_idx(nums, &j, -1);
	    			continue;
	    		}
	    		if (temp < diff)
	    		{
	    			upd_idx(nums, &i, 1);
	    		}
	    		else
	    		{
		    		upd_idx(nums, &j, -1);
	    		}
	    	}
    	}
    }
    return quad;
}

int cmp(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

void upd_idx (int *nums, int *idx, int add)
{
	do
	{
		*idx = *idx + add;
	}while (nums[idx] == nums[idx - add]);

	return;
}
