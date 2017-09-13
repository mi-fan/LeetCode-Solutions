/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

#include <stdio.h>

#define AREA(x, y)  (x*y)

int main()
{
	int height[10]
	int area = maxArea(height, 10);
	return 0;
}

int maxArea(int *height, int heightSize)
{ 
	int max  = 0;
	int area = 0;
	int full;
	int now;
	
	l = 0;  //lower side of max area
	r = heightSize;  //upper side of max area
	full = (height[l] >= height[r])? AREA(height[l]*heightSize) : AREA(height[r]*heightSize);
	max = full;

	while (l < r)
	{
		if (height[l] < height[r])
		{
			while()
		}
	}

	return max;
}