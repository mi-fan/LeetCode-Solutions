//Given a digit string, return all possible letter combinations that the number could represent.

//A mapping of digit to letters (just like on the telephone buttons) is given below.

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize)
 {
    int pow_4(int times);
	int combinations(char *com, char *digits, int pos, int size);

    char **com;
    int size = strlen(digits);
    int rows = pow_4(size);
    int i, j;
    int num, max;

    *returnSize = 0;

    com = (char**)malloc(rows*sizeof(char*));
    for (i = 0; i < rows; i++)
    {
    	com[i] = (char*)malloc(size*sizeof(char));
    }

    if (!size)
        return com;

    num = (int)(digits[0]) - 48;
    if (num == 7 || num == 9)
    	max = 4;
    else max = 3;

    while (1)
    {
    	if (1 == combinations(com[(*returnSize)++], digits, 0, size))
    		break;
    }
    return com;
}

int pow_4(int times)
{
	int pow = 1;
	while (times)
	{
		pow *= 4;
		times--;
	}
	return pow;
}

//pos: current selected digit to choose letter
int combinations(char *arr, char *digits, int pos, int size)
{
	const char key[10][4] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	static int use[1024];  //the using order of letters of each digit
	int num = (int)(digits[pos]) - 48;

	arr[pos] = key[num][use[pos]];

	if (pos == size -1)
	{
		use[pos]++;
        arr[pos + 1] = '\0';
		if (((num == 7 || num == 9) && use[pos] == 4) || ((num != 7 && num != 9) && use[pos] == 3))
		{
			use[pos] = 0;
			return 1;
		}

		return 0;
	}

	if (1 == combinations(arr, digits, pos + 1, size))
    {
		use[pos]++;

        if (((num == 7 || num == 9) && use[pos] == 4) || ((num != 7 && num != 9) && use[pos] == 3))
        {
            use[pos] = 0;
            return 1;
        }
    }

	return 0;
}