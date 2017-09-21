There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5;

int insertArray(int* arr, int begin, int end, int n);
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double mid;
    int j, p, pos1, pos2;

    if (nums1Size == 0 && nums2Size == 0)
    	return 0;

    pos1 = (nums1Size + nums2Size - 1)/2; //first number index to get median
    pos2 = (nums1Size + nums2Size)/2;     //second number index to get median
    j = 0;

    for (j = 0; j < nums2Size; j++)
    {
    	p = insertArray(nums1, 0, nums1Size - 1, nums2[j]);
    	if (p + j == pos1)
    	{
    		if (pos1 == pos2)
    			return nums2[j];
            if (j + 1 >= nums2Size)
                mid = nums1[p];
            else if (p >= nums1Size)
                mid = nums2[j + 1];
            else
                mid = (nums2[j + 1] > nums1[p])? (double)nums1[p] : (double)nums2[j + 1];
    		return ((double)nums2[j] + mid)/2;
    	}
    	else if(p + j == pos2)
        {
            return ((double)(nums1[p - 1] + nums2[j]))/2;
        }
    	else if (p + j > pos2)
    	{
    		if (pos1 == pos2)
    			return nums1[pos1 - j];
    		else
    			return ((double)(nums1[pos1 - j] + nums1[pos1 - j + 1]))/2;
    	}
    }

    if (++j >= nums2Size)
	{
		j = nums2Size;
		if (pos1 == pos2)
			return nums1[pos1 - j];
		else
			return ((double)(nums1[pos1 - j] + nums1[pos1 - j + 1]))/2;
	}
  	return mid;
}

int insertArray(int* arr, int begin, int end, int n)
{
    if (end - begin <= 1 && n > arr[begin] && n < arr[end])
        return end;
	if (n < arr[begin])
		return 0;
	if (n >= arr[end])
		return (end + 1);

	int pos;
	int mid = (begin + end)/2;

	if (n == arr[mid])
		return (mid + 1);

	if (n < arr[mid])
		pos = insertArray(arr, begin, mid, n);
	else
		pos = insertArray(arr, mid, end, n);

	return pos;
}