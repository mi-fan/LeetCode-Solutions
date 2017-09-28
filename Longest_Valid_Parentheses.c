Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

(((())())(((()))(()((((((((((((((((((((((()))))))))))))))))

int longestValidParentheses(char* s) {
    int i, j, p, q, size, max = 0;
    int count = 0;

    size = strlen(s);

    if (size <= 1)
    	return 0;

    i = 0;
    j = size - 1;
    while (s[i] != '(' && i < size) i++;
    while (s[j] != ')' && j > 0) j--;

    p = i;
    while (i <= j)
    {
    	if (s[i] == '(') count++;
    	else count--;

    	if (count == 0)
            max = ((i - p + 1) > max)? (i - p + 1) : max;
        else if (count < 0)
        {
            p = i + 1;
            count = 0;
        }
    	i++;
    }
    count = 0;
    q = j;
    while (j >= p)
    {
    	if (s[j] == ')') count++;
    	else count--;

    	if (count == 0)
            max = ((q - j + 1) > max)? (q - j + 1) : max;
        else if (count < 0)
        {
            q = j - 1;
            count = 0;
        }
    	j--;
    }


    return max;
}