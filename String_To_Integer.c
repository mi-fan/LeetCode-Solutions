Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

inline int getNumber(char c)
{
	if (c >= 48 && c <= 57)
		return c - 48;
	else 
		return -1;
}

inline int isSignature(char c)
{
	if (c == '+')
		return 1;
    else if (c == '-')
        return -1;
	else
		return 0;
}

int myAtoi(char* str) {
    int len = strlen(str);
    int num = 0;
    int old = num;
    int sign = 1;
    int i = 0;

    if (len == 0)
    	return 0;

    while (str[i] == ' ')i++;
    if (i >= len) return 0;

    if ((sign = isSignature(str[i])) != 0) i++;
    else if ((num = getNumber(str[i])) >= 0) i++;
    else return 0;

    while (getNumber(str[i]) >= 0 && i < len)
    {
        old = num;
    	num = num * 10 + getNumber(str[i]);
        if ((num < 0 || old != num/10) && sign >= 0)
            return 2147483647;
        if ((num < 0 || old != num/10) && sign < 0)
            return -2147483648;
    	i++;
    }

    if (sign)
        return num*sign;

    return num;
}