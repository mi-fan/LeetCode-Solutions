Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

int match(char *m, char *n);
int strStr(char* haystack, char* needle) {
    int s1 = strlen(haystack);
    int s2 = strlen(needle);
    
    if (s1 == 0 && s2 == 0)
        return 0;

    if (s1 < s2)
    	return -1;

    if (s2 == 0)
    	return 0;
    
    if (s1 == s2)
    {
        if(memcmp(haystack, needle, s1) == 0)
            return 0;
        return -1;
    }

    int i, j;

    for (i = 0; i < s1 - s2 + 1; i++)
    {
    	if(haystack[i] == needle[0])
    	{
    		if (match(&haystack[i], needle))
    			return i;
    	}
    }

    return -1;
}

int match(char *m, char *n)
{
	int s1 = strlen(m);
	int s2 = strlen(n);

	if (s2 == 0)
		return 1;
	if (s1 == 0)
		return 0;

	if (m[0] == n[0])
		return match(&m[1], &n[1]);
    else 
        return 0;
}