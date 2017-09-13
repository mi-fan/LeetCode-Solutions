//Write a function to find the longest common prefix string amongst an array of strings. 

#include <stdio.h>

char* longestCommonPrefix(char** strs, int strsSize);

int main(void)
{
	return 0;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    int n = 0;
	int i = 0;
    
    if (strsSize == 0)
    {
        return "";
    }
    else if (strsSize == 1)
    {
        return *strs;
    }

	while(1)
	{
		for (i = 0; i < strsSize - 1; i++)
		{
			if (strs[i][n] != strs[i+1][n])
            {
                strs[i][n] = '\0';
                return strs[i];
            }
		}
		n++;
	}
}
