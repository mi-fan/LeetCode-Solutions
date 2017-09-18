Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "( ( ( ) ) )",
  "( ( ) ( ) )",
  "( ( ) ) ( )",
  "( ) ( ( ) )",
  "( ) ( ) ( )"
]

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
 	int ln = 0;
 	int rn = 0;
 	char **str = (char **)malloc(1024*n*sizeof(char*));

    *returnSize = 0;
     str[0] = (char *)malloc(2*n*sizeof(char));
    if (n == 0)
    {
        *returnSize = 1;
        return str;
    }

 	addParenthesis(str, ln, rn, n, returnSize);

 	return str;
 }

 void addParenthesis(char **str, int ln, int rn, int n, int *rs)
 {
 	int pos = ln + rn;

 	if (pos == (2*n - 1))
 	{
 	    int i;
 		str[*rs][pos] = ')';

 		for (i = 0; i <= pos; i++)
            printf("%c ", str[*rs][i]);
        printf("\n");

        (*rs)++;

        str[*rs] = (char *)malloc(2*n*sizeof(char));
        memcpy(str[*rs], str[(*rs) - 1], 2*n*sizeof(char));
 		return;
 	}

 	if (ln < n)
 	{
 		str[*rs][pos] = '(';
 		addParenthesis(str, ln + 1, rn, n, rs);
 	}

 	if (ln > rn)
 	{
 		str[*rs][pos] = ')';
 		addParenthesis(str, ln, rn + 1, n, rs);
 	}

 	return;
 }