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
    
    for (start = 0, end = numsSize - 1; start < end - 2; )
    {
    	diff = target - (nums[start] + nums[end]);
    	for (i = start + 1, j = end - 1; i < j; )
    	{
    		temp = nums[i] + nums[j];
    		if (temp == diff)
    		{
    			quad[*returnSize][0] = nums[start];
    			quad[*returnSize][1] = nums[i];
    			quad[*returnSize][2] = nums[j];
    			quad[*returnSize][3] = nums[end];
    			(*returnSize)++;
    			i++;
    			j--;
    			continue;
    		}
    		if (temp < diff)
    			i++;
    		else
	    		j--;
    	}
    	if (flag == 0)
    	{
    		flag = 1;
    		old_s = start;
    		do
    		{
    			start++;
    		}while (nums[start] == nums[start - 1] && start < end - 2);
    		new_s = start;
    	}
    	else if (flag == 1)
    	{
    		flag = 2;
    		start = old_s;
    		do
    		{
    			end--;    			
    		}while (nums[end] == nums[end + 1] && end > start + 2);
    		new_e = start;
    	}
    	else
    	{
    		flag = 0;
    		start = new_s;
    		end = new_e;
    	}

    }
    return quad;
}

int cmp(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}